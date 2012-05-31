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
#include <Foundation/NSDate.h>
NSDate*
	NSDate::initWithTimeIntervalSince1970(NSTimeInterval seconds)
{
	self->timesSeconds = seconds;
	return self;
}
NSDate*
	NSDate::initWithTimeIntervalSinceReferenceDate(NSTimeInterval seconds)
{
	self->timesSeconds = seconds - NSTimeIntervalSince1970 ;
	return self;
}
NSDate*
	NSDate::init()
{
	self->initWithTimeIntervalSince1970((NSTimeInterval)time(nil));
	return self;
}
NSDate*
	NSDate::dateWithTimeIntervalSince1970(NSTimeInterval seconds)
{
	return (NSDate*) alloc()->initWithTimeIntervalSince1970(seconds);
}
NSDate*
	NSDate::dateWithTimeIntervalSinceReferenceDate(NSTimeInterval seconds)
{
	return (NSDate*) alloc()->dateWithTimeIntervalSinceReferenceDate(seconds);
}
NSDate*
	NSDate::initWithTimeIntervalSinceNow(NSTimeInterval seconds)
{
	self->timesSeconds = time(nil) + seconds;
	return self;
}

NSDate*
	NSDate::dateWithTimeIntervalSinceNow(NSTimeInterval seconds)
{
	return (NSDate*) alloc()->initWithTimeIntervalSinceNow(seconds);
}

void
NSDate::dealloc()
{
}
NSDate*
	NSDate::distantPast()
{
	return (NSDate*)alloc()->initWithTimeIntervalSinceNow(-100*365*24*36000);
}
NSDate*
	NSDate::distantFuture()
{
	return (NSDate*)alloc()->initWithTimeIntervalSinceNow(100*365*24*36000);
}