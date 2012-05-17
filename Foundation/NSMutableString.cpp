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
#include <Foundation/NSMutableString.h>
#include <Foundation/NSData.h>
#define super NSString
NSString*
	NSMutableString::description()
{
	return NSSTR(ref->m_sString.c_str());
}
void
	NSMutableString::insertString_atIndex(NSString *aString ,NSUInteger anIndex)
{
	self->ref->toStdString().insert(anIndex,aString->cStringUsingEncoding(NSASCIIStringEncoding));
}
NSMutableString*
	NSMutableString::initWithCapacity(NSUInteger capacity)
{
	return self;
}
NSMutableString*
	NSMutableString::stringWithCapacity(NSUInteger capacity)
{
	return (NSMutableString*)alloc()->initWithCapacity(capacity)->autorelease();
}
void
	NSMutableString::dealloc()
{
}
void
	NSMutableString::deleteCharactersInRange(NSRange aRange)
{
	self->ref->toStdString().erase(aRange.location,aRange.length);
}
 void
	NSMutableString::replaceCharactersInRange_withString(NSRange aRange , NSString * aString)
 {
	 self->ref->toStdString().replace(aRange.location,aRange.length,aString->cStringUsingEncoding(NSASCIIStringEncoding));
 }
void
	NSMutableString::appendString(NSString* aString)
{
	self->ref->m_sString.append(aString->cStringUsingEncoding(NSASCIIStringEncoding));
}
void
	NSMutableString::appendFormat(NSString* format,...)
{
	va_list arguments;
	va_start(arguments,format);
	NSString* appendString = (NSString*)NSString::alloc()->initWithFormat_locale_arguments(format,nil,arguments)->autorelease();
	va_end(arguments);

	self->appendString(appendString);
}
NSUInteger
	NSMutableString::replaceOccurrencesOfString_withString_options_range(NSString * target,NSString * replacement , NSStringCompareOptions opts ,NSRange searchRange )
{
	NSUInteger targetLength = target->length();
	NSInteger foundPlace;
	while(string::npos != (foundPlace = self->ref->toStdString().find(target->cStringUsingEncoding(NSASCIIStringEncoding))))
	{
		ref->m_sString =  ref->m_sString.replace(foundPlace ,targetLength, replacement->cStringUsingEncoding(NSASCIIStringEncoding));
	}
	return 0;
}
void
	NSMutableString::setString(NSString* aString)
{
	ref->m_sString.assign(string(aString->ref->m_sString.c_str()));
}
NSMutableString*
	NSMutableString::alloc()
{
	NSString* instance;
	if(instance = super::alloc())
	{
	}
	return (NSMutableString*)instance;
}