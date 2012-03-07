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
NSString::NSString(const char* str)
{
	ref = CCS(str);
}
std::string
	NSString::description()
{
	return ref->toStdString();
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
	NSString::retain()
{ 
	ref->retain();
	self->m_uReference++;
}
vid
	NSString::autorelease()
{
	CCPoolManager::getInstance()->addObject(self);
	self->m_bManaged = self;

	ref->autorelease();

	return this;
}
void
	NSString::dealloc()
{
	ref->release();
}
//todo enconding
NSString*
	NSString::initWithCString_encoding(const char* nullTerminatedCString,NSStringEncoding encoding)
{
	_encoding = encoding ;
	ref = CCS(nullTerminatedCString);
	return self;
}
NSString*
	NSString::stringWithCString_encoding(const char* nullTerminatedCString,NSStringEncoding encoding)
{
	NSString* mem = alloc()->initWithCString_encoding(nullTerminatedCString,encoding);
	mem->autorelease();
	return mem;
}
NSString*
	NSString::initWithString(NSString* aString)
{
	self->ref = CCS(aString->description().c_str());
	self->_encoding = aString->get_encoding();
	return self;
}
NSString*
	NSString::stringWithString(NSString* aString)
{
	return (NSString*) alloc()->initWithString(aString)->autorelease();
}
