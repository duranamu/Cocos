/****************************************************************************
	Cocos OpenSource Project
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
#include "NSArray.h"
#include "Foundation.h"
NSArray*
	NSArray::alloc()
{
	NSArray* parray =  new NSArray();
	if(!parray )
	{
		CC_SAFE_DELETE(parray);
	}
	return parray;
}
NSArray*
	NSArray::initWithObjects(NSObject* msg , ...)
{
	if(msg)
		self->ref->addObject(msg);

	va_list argp;
	NSInteger argno = 0;
	NSObject* para;

	va_start(argp , msg);
	while(1)
	{
		para = va_arg( argp , NSObject * );
		if( para != nil)
		{
			argno++;
			self->ref->addObject(para);
		}else{
			break;
		}
	}
	va_end ( argp);
	return self;
}
NSArray*
NSArray::initWithObject(NSObject* obj)
{
	if(obj)
	{
		self->ref->addObject(obj);
	}
	
	return self;
}
NSArray*
	NSArray::arrayWithCapacity(NSUInteger num)
{
	NSArray* mem =  new NSArray(num);
	if(!mem )
	{
		CC_SAFE_DELETE(mem);
	}
	return mem;
}
NSArray::NSArray(NSUInteger num)
{
	ref = CCArray::arrayWithCapacity(num);
}
NSArray::NSArray()
{
	ref = CCArray::array();
}
NSObject* NSArray::objectAtIndex(NSUInteger index)
{
	return (NSObject*) ref->objectAtIndex(index);
}
NSObject* 
	NSArray::randomObject()
{
	return (NSObject*) ref->randomObject();
}
NSArray*
	NSArray::array()
{
	return alloc();
}
