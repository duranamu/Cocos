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
#pragma once
#include <Foundation/NSObject.h>
NS_INTERFACE (NSNumber , NSObject)
union{
 char _char;
 short _short;
 int _int;
 long _long;
 long long _longLong;
 float _float;
 double _double;
  BOOL _bool;
  NSDecimal decimal;
  NSInteger integer;

 unsigned char unsignedChar;
 unsigned short unsignedShort;
 unsigned int unsignedInt;
 unsigned long unsignedLong;
 unsigned long long unsignedLongLong;
 NSUInteger unsignedInteger;
}data;
NSNumber* 
	initWithBool(BOOL);
NSNumber* 
	initWithChar(char);
NSNumber* 
	initWithShort(short);
NSNumber* 
	initWithInt(int);
NSNumber* 
	initWithLong(long);
NSNumber* 
	initWithLongLong(long long);
NSNumber* 
	initWithFloat(float);
NSNumber* 
	initWithDouble(double);
NSNumber* 
	initWithInteger(NSInteger);

NSNumber* 
	initWithUnsignedChar(unsigned char);
NSNumber* 
	initWithUnsignedShort(unsigned short);
NSNumber* 
	initWithUnsignedInt(unsigned int);
NSNumber* 
	initWithUnsignedLong(unsigned long);
NSNumber* 
	initWithUnsignedLongLong(unsigned long long);
NSNumber* 
	initWithUnsignedInteger(NSUInteger);


static NSNumber * 
	numberWithBool(BOOL value);
static NSNumber * 
	numberWithChar(char );
static NSNumber * 
	numberWithShort(short);
static NSNumber * 
	numberWithInt(int);
static NSNumber * 
	numberWithLong(long);
static NSNumber * 
	numberWithLongLong(long long);
static NSNumber * 
	numberWithFloat(float);
static NSNumber * 
	numberWithDouble(double);
static NSNumber * 
	numberWithInteger(NSInteger);

static NSNumber * 
	numberWithUnsignedChar(unsigned char);
static NSNumber * 
	numberWithUnsignedShort(unsigned short);
static NSNumber *
	numberWithUnsignedInt(unsigned int);
static NSNumber * 
	numberWithUnsignedLong(unsigned long);
static NSNumber * 
	numberWithUnsignedLongLong(unsigned long long);
static NSNumber * 
	numberWithUnsignedInteger(NSUInteger);

 char charValue();
 short shortValue();
 int intValue();
 long longValue();
 long long longLongValue();
 float floatValue();
 double doubleValue();
  BOOL boolValue();
  NSDecimal decimalValue();
  NSInteger integerValue();

 unsigned char unsignedCharValue();
 unsigned short unsignedShortValue();
 unsigned int unsignedIntValue();
 unsigned long unsignedLongValue();
 unsigned long long unsignedLongLongValue();
 NSUInteger unsignedIntegerValue();

NS_END