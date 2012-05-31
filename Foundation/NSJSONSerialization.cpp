/****************************************************************************
	Cocos  Project
			hosting	github.com
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include <Foundation/NSJSONSerialization.h>
#include <json/json.h>
#include <iconv/iconv.h>
#include <Foundation/NSString.h>
#include <Foundation/NSMutableDictionary.h>
#include <Foundation/NSMutableArray.h>
#define JSValue Json::Value 
#define JSReader Json::Reader
#define JSWritter Json::Writer
#define JSValueIterator Json::Value::iterator
using namespace Json;
int code_convert(char* from_charset,char* to_charset,char* inburf,size_t inlen,char * outbuf,size_t outlen)
{
	iconv_t cd;
	const char* temp = inburf;
	const char** pin =&temp;
	char **pout =&outbuf;

	cd = iconv_open(to_charset,from_charset);

	if(cd == 0)return -1;

	memset(outbuf,0,outlen);

	if(iconv(cd,pin,&inlen,pout,&outlen)==-1) return -1;

	iconv_close(cd);
	return 0;
}
void
	parseJSObject(JSValue value ,NSMutableDictionary* dict)
{
	JSValueIterator it = value.begin();
	while(it != value.end())
	{
		const char* key = it.memberName();
		const char* value_str = value[key].asCString();
		dict->setObject_forKey(NSSTR(value_str),NSSTR(key));
		it++;
	}
}
void
	parseJSArray(JSValue value ,NSMutableArray* array)
{
	for(NSUInteger i =0 ;i< value.size();i++)
	{
		if(value[i].isArray())
		{
			NSMutableArray* arr = NSMutableArray::alloc()->init();
			arr->retain();
			parseJSArray(value[i],arr);
			array->addObject(arr);
		}else{
			NSMutableDictionary* dict = NSMutableDictionary::dictionary();
			dict->retain();
			parseJSObject(value[i],dict);
			array->addObject(dict);
		}
	}
}

NSObject*
	NSJSONSerialization::JSONObjectWithData_options_error
		(NSData* data ,NSJSONReadingOptions option ,NSError** erro)
{
	//todo fix nil
	NSString* content = NSString::alloc()->initWithData_encoding(data,nil);
	char* str = strdup(content->cStringUsingEncoding(NSASCIIStringEncoding));
	//NSUInteger inlen = strlen(str);
	//char* out = new char[300];
	//NSUInteger oulen =300;

	//NSInteger code =code_convert("gb2312","utf-8",str,inlen,out,oulen);
	JSValue root;   
    JSReader reader;
    if(reader.parse( str, root ))
	{
		if(root.isArray())
		{
			NSMutableArray* jsonObject = NSMutableArray::alloc()->init();
			jsonObject->retain();
			parseJSArray(root,jsonObject);
			return jsonObject;
		}else{
			NSMutableDictionary* jsonObject = NSMutableDictionary::dictionary();
			jsonObject->retain();
			parseJSObject(root,jsonObject);
			return jsonObject;
		}
		
	}
	content->release();
}
void
	NSJSONSerialization::dealloc()
{
}