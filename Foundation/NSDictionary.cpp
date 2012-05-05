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
#include <Foundation/NSDictionary.h>
#include <stdarg.h>
NSDictionary*
	NSDictionary::dictionary()
{
	return (NSDictionary*) alloc()->init()->autorelease();
}
NSDictionary*
	NSDictionary::dictionaryWithObjectAndKeys(NSObject* obj,NSString* str,...)
{
	NSDictionary* dict; ;
	if(dict = alloc()->init())
	{
		if(obj && str)
		dict->ref->setObject(obj,str->ref->m_sString);
		NSObject* para_obj;
		NSString* para_str;

		va_list argp;
		va_start(argp , str);
		while(1)
		{
			para_obj = va_arg( argp , NSObject * );
			para_str = va_arg( argp , NSString * );
		if( para_obj != nil)
		{
			dict->ref->setObject(para_obj,para_str->ref->m_sString);
		}else{
			break;
		}
		}
	va_end ( argp);
	}
	dict->autorelease();
	return dict;
}
NSDictionary*
	NSDictionary::initWithObjectsAndKeys(NSObject* obj,NSString* str,...)
{
	if(obj && str)
		self->ref->setObject(obj,str->ref->m_sString);
	NSObject* para_obj;
	NSString* para_str;

	va_list argp;
	va_start(argp , str);
	while(1)
	{
		para_obj = va_arg( argp , NSObject * );
		para_str = va_arg( argp , NSString * );
		if( para_obj != nil)
		{
			self->ref->setObject(para_obj,para_str->ref->m_sString);
		}else{
			break;
		}
	}
	va_end ( argp);
	self->autorelease();
	return self;
}
void
	NSDictionary::dealloc()
{
	ref->release();
}
	NSDictionary::NSDictionary()
{
	 ref = new CCDictionary<std::string,NSObject*>();
	 self->copying = self;
}
vid
	NSDictionary::copyWithZone(NSZone* aZone)
{
	NSDictionary* dict = alloc()->init();

	return dict;
}
void
	NSDictionary::gotoBeginObject()
{
	if(self->ref)
	{
		ref->begin();
	}
}
vid
	NSDictionary::nextObject()
{
	std::string* str = new std::string();
	ref->next(str);
	return str;
}