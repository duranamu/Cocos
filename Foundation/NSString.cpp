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
#include <Foundation/NSString.h>
#include <Foundation/NSData.h>
#include <Foundation/NSObjectProtocol.h>
NSString*
	NSString::description()
{
	return self;
}
NSString*
	NSString::initWithData_encoding(NSData* data , NSStringEncoding encoding)
{
	 return self->initWithBytes_length_encoding(data->bytes() ,data->length(),encoding);
}
//todo enconding
NSString*
	NSString::initWithBytes_length_encoding(const vid bytes ,NSUInteger length ,NSStringEncoding enconding)
{
	_encoding = enconding;
	char* _str = (char*) malloc(sizeof(char)*length);
	if(_str)
	{
		memcpy(_str,bytes,length);
		self->ref = CCS(_str);
	}
	return self;
}
void
	NSString::dealloc()
{
	/*self->ref->release();
	self->ref = nil;*/
}
//todo enconding
NSString*
	NSString::initWithCString_encoding(const char* nullTerminatedCString,NSStringEncoding encoding)
{
	_encoding = encoding ;
	self->ref = CCS(nullTerminatedCString);
	return self;
}
NSString*
	NSString::stringWithCString_encoding(const char* nullTerminatedCString,NSStringEncoding encoding)
{
	return (NSString*)alloc()->initWithCString_encoding(nullTerminatedCString,encoding)->autorelease();
}
NSString*
	NSString::initWithString(NSString* aString)
{
	self->ref= CCS(aString->cStringUsingEncoding(NSASCIIStringEncoding));
	self->_encoding = aString->get_encoding();
	return self;
}
NSString*
	NSString::stringWithString(NSString* aString)
{
	return (NSString*) alloc()->initWithString(aString)->autorelease();
}
void
	NSString::objectDidUnload()
{
	self->ref->release();
	self->ref = nil;
}
void
	NSString::objectDidLoad()
{
	self->ref = new CCString();
}
NSString*
	NSString::initWithContentOfFile_encoding_erro(NSString* path ,NSStringEncoding enc , NSError** error)
{
//	self->ref->release();
	self->ref->toStdString().append(CCString::stringWithContentsOfFile(path->cStringUsingEncoding(NSASCIIStringEncoding)));
	return self;
}
NSString*
	NSString::stringWithContentOfFile_encoding_erro(NSString* path ,NSStringEncoding enc , NSError** error)
{
	return (NSString*)alloc()->initWithContentOfFile_encoding_erro(path,enc,error)->autorelease();;
}
NSUInteger
	NSString::length()
{
	return self->ref->m_sString.length();
}
NSString*
	NSString::initWIthFormat(NSString* format,...)
{
   va_list arguments;
   va_start(arguments,format);
   initWithFormat_locale_arguments(format,nil,arguments);
   va_end(arguments);

   return self;
}
NSString*
	NSString::initWithFormat_locale_arguments(NSString* format ,vid local ,va_list arguments)
{
   	NSInteger foundPlace= format->ref->m_sString.find("%");
	while( string::npos != (foundPlace = format->ref->m_sString.find("%")))
	{
		char specifier = format->cStringUsingEncoding(NSASCIIStringEncoding)[foundPlace+1];
		if('c' == specifier){
			  char para[8];
			 sprintf(para,"%c",va_arg(arguments,unsigned char));
			 format->ref->m_sString = format->ref->m_sString.insert(foundPlace+2,para);
		}else if('d' == specifier | 'D' == specifier | 'i' == specifier){
			 char para[8];
			sprintf(para,"%d",va_arg(arguments,int));
			format->ref->m_sString = format->ref->m_sString.insert(foundPlace+2,para);
		}else if('s' == specifier) {
			format->ref->m_sString = format->ref->m_sString.insert(foundPlace+2,va_arg(arguments, char*));
		}else if('p' == specifier) {
			 char para[30];
			sprintf(para,"%p",va_arg(arguments,void*));
			format->ref->m_sString = format->ref->m_sString.insert(foundPlace+2,para);
		}else if('f' == specifier){
			 char para[8];
			sprintf(para,"%f",va_arg(arguments,double));
			format->ref->m_sString = format->ref->m_sString.insert(foundPlace+2,para);
		}else if('u' == specifier | 'U' == specifier){
			 char para[8];
			sprintf(para,"%u",va_arg(arguments,unsigned int));
			format->ref->m_sString = format->ref->m_sString.insert(foundPlace+2,para);
		}else if('@' == specifier){
			NSString* descriptionString = va_arg(arguments,NSObject*)->description();
			format->ref->m_sString = format->ref->m_sString.insert(foundPlace+2,
				descriptionString->cStringUsingEncoding(NSASCIIStringEncoding));
		}
		format->ref->m_sString.erase(foundPlace,2);
	}

   ref->m_sString.assign(format->ref->m_sString);
   return self;
}
const char *
	NSString::cStringUsingEncoding(NSStringEncoding encoding)
{
	return ref->m_sString.c_str();
}

NSString*
	NSString::stringWithFormat(NSString* format ,...)
{
   va_list arguments;
   va_start(arguments,format);
   NSString* string = (NSString*)alloc()->initWithFormat_locale_arguments(format,nil,arguments)->autorelease();
   va_end(arguments);

   return string;
}

NS_CACHE_OBJECT_INIT(NSString);

NSComparisonResult
	NSString::compare(NSString* aString)
{
	NSInteger result = self->ref->m_sString.compare(aString->ref->m_sString);

	if(result == 0)
	{
		return NSOrderedSame;
	}else if(result > 0)
	{
		return NSOrderedAscending;
	}else {
		return NSOrderedDescending;
	}
}