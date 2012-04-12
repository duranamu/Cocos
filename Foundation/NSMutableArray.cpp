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
#include <Foundation/NSMutableArray.h>
NSMutableArray*
	NSMutableArray::initWithObjects(NSObject* msg , ...)
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
NSMutableArray*
	NSMutableArray::initWithObject(NSObject* obj)
{
	if(obj)
	{
		self->ref->addObject(obj);
	}
	
	return self;
}
NSMutableArray*
	NSMutableArray::arrayWithCapacity(NSUInteger num)
{
	NSMutableArray* mem =  new NSMutableArray(num);
	if(!mem )
	{
		CC_SAFE_DELETE(mem);
	}
	return mem;
}
NSMutableArray::NSMutableArray(NSUInteger num)
{
	ref = CCArray::arrayWithCapacity(num);
}
NSMutableArray::NSMutableArray()
{
	ref = CCArray::array();
	self->copying = self;
	ref->retain();
}
NSObject* 
	NSMutableArray::objectAtIndex(NSUInteger index)
{
	return (NSObject*) ref->objectAtIndex(index);
}
NSObject* 
	NSMutableArray::randomObject()
{
	return (NSObject*) ref->randomObject();
}
NSMutableArray*
	NSMutableArray::array()
{
	return (NSMutableArray*) alloc()->init()->autorelease();
}
BOOL
	NSMutableArray::removeObject(NSObject* obj)
{
		if(ref->containsObject(obj))
		{ 
			ref->removeObject(obj); 
			return YES;
		}else{ 
			return NO;
		}
}
void
	NSMutableArray::removeLastObject()
{
	self->ref->removeLastObject();
}
void
	NSMutableArray::removeAllObjects()
{
	self->ref->removeAllObjects();
}
void
	NSMutableArray::dealloc()
{
	if(self->m_bManaged == false)
	{
		ref->removeAllObjects();
		ref->release();
		ref = nil;
	}
}
vid
	NSMutableArray::copyWithZone(NSZone* aZone)
{
	NSMutableArray* newArray  = (NSMutableArray*)NSMutableArray::alloc()->init();
	nfor(NSObject* ,obj,self)
		newArray->addObject(obj);
	nend

	return newArray;
}
vid
	NSMutableArray::nextObject()
{
	if(indexedObject <= endedObejct && self->ref->data->num)
	{
		return *(indexedObject++);
	}
		return nil;
}
void
	NSMutableArray::gotoBeginObject()
{
	if(self->ref->data->num )
	{
		indexedObject = (NSObject**)self->ref->data->arr;
		endedObejct   = (NSObject**)indexedObject + self->ref->data->num-1;
	}
}
NS_CACHE_OBJECT_INIT(NSMutableArray)