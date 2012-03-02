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
#include <Foundation/NSNumber.h>
BOOL
	NSNumber::boolValue(){return self->data._bool;}
NSNumber*
	NSNumber::initWithBool(BOOL value)
{
	self->data._bool = value;
	return self;
}
NSNumber*
	NSNumber::numberWithBool(BOOL value)
{
	return (NSNumber*)alloc()->initWithBool(value)->autorelease();
}
char
	NSNumber::charValue(){return self->data._char;}
NSNumber*
	NSNumber::initWithChar(char value)
{
	self->data._char = value;
	return self;
}
NSNumber*
	NSNumber::numberWithChar(char value)
{
	return (NSNumber*)alloc()->initWithChar(value)->autorelease();
}
short
	NSNumber::shortValue(){return self->data._short;}
NSNumber*
	NSNumber::initWithShort(short value)
{
	self->data._short = value;
	return self;
}
NSNumber*
	NSNumber::numberWithShort(short value)
{
	return (NSNumber*)alloc()->initWithShort(value)->autorelease();
}
int
	NSNumber::intValue(){return self->data._int;}
NSNumber*
	NSNumber::initWithInt(int value)
{
	self->data._int = value;
	return self;
}
NSNumber*
	NSNumber::numberWithInt(int value)
{
	return (NSNumber*)alloc()->initWithInt(value)->autorelease();
}

long
	NSNumber::longValue(){return self->data._long;}
NSNumber*
	NSNumber::initWithLong(long value)
{
	self->data._long = value;
	return self;
}
NSNumber*
	NSNumber::numberWithLong(long value)
{
	return (NSNumber*)alloc()->initWithLong(value)->autorelease();
}

long long 
	NSNumber::longLongValue(){return self->data._longLong;}
NSNumber*
	NSNumber::initWithLongLong(long long value)
{
	self->data._longLong = value;
	return self;
}
NSNumber*
	NSNumber::numberWithLongLong(long long value)
{
	return (NSNumber*)alloc()->initWithLongLong(value)->autorelease();
}

float 
	NSNumber::floatValue(){return self->data._float;}
NSNumber*
	NSNumber::initWithFloat(float value)
{
	self->data._float = value;
	return self;
}
NSNumber*
	NSNumber::numberWithFloat(float value)
{
	return (NSNumber*)alloc()->initWithFloat(value)->autorelease();
}

double
	NSNumber::doubleValue(){return self->data._double;}
NSNumber*
	NSNumber::initWithDouble(double value)
{
	self->data._double = value;
	return self;
}
NSNumber*
	NSNumber::numberWithDouble(double value)
{
	return (NSNumber*)alloc()->initWithDouble(value)->autorelease();
}

NSInteger
	NSNumber::integerValue(){return self->data.integer;}
NSNumber*
	NSNumber::initWithInteger(NSInteger value)
{
	self->data.integer = value;
	return self;
}
NSNumber*
	NSNumber::numberWithInteger(NSInteger value)
{
	return (NSNumber*)alloc()->initWithInteger(value)->autorelease();
}

unsigned char 
	NSNumber::unsignedCharValue(){return self->data.unsignedChar;}
NSNumber*
	NSNumber::initWithUnsignedChar(unsigned char value)
{
	self->data.unsignedChar = value;
	return self;
}
NSNumber*
	NSNumber::numberWithUnsignedChar(unsigned char value)
{
	return (NSNumber*)alloc()->initWithUnsignedChar(value)->autorelease();
}

unsigned int
	NSNumber::unsignedIntValue(){return self->data.unsignedInt;}
NSNumber*
	NSNumber::initWithUnsignedInt(unsigned int value)
{
	self->data.unsignedInt = value;
	return self;
}
NSNumber*
	NSNumber::numberWithUnsignedInt(unsigned int value)
{
	return (NSNumber*)alloc()->initWithUnsignedInt(value)->autorelease();
}


unsigned short 
	NSNumber::unsignedShortValue(){return self->data.unsignedShort;}
NSNumber*
	NSNumber::initWithUnsignedShort(unsigned short value)
{
	self->data.unsignedShort = value;
	return self;
}
NSNumber*
	NSNumber::numberWithUnsignedShort(unsigned short value)
{
	return (NSNumber*)alloc()->initWithUnsignedShort(value)->autorelease();
}

unsigned long 
	NSNumber::unsignedLongValue(){return self->data.unsignedLong;}
NSNumber*
	NSNumber::initWithUnsignedLong(unsigned long value)
{
	self->data.unsignedLong = value;
	return self;
}
NSNumber*
	NSNumber::numberWithUnsignedLong(unsigned long value)
{
	return (NSNumber*)alloc()->initWithUnsignedLong(value)->autorelease();
}

unsigned long long
	NSNumber::unsignedLongLongValue(){return self->data.unsignedLongLong;}
NSNumber*
	NSNumber::initWithUnsignedLongLong(unsigned long long value)
{
	self->data.unsignedLongLong = value;
	return self;
}
NSNumber*
	NSNumber::numberWithUnsignedLongLong(unsigned long long value)
{
	return (NSNumber*)alloc()->initWithUnsignedLongLong(value)->autorelease();
}
NSUInteger 
	NSNumber::unsignedIntegerValue(){return self->data.unsignedInteger;}
NSNumber*
	NSNumber::initWithUnsignedInteger(NSUInteger value)
{
	self->data.unsignedInteger = value;
	return self;
}
NSNumber*
	NSNumber::numberWithUnsignedInteger(NSUInteger value)
{
	return (NSNumber*)alloc()->initWithUnsignedInteger(value)->autorelease();
}

void
	NSNumber::dealloc(){};