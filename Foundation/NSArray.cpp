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
#include <Foundation/NSArray.h>
NSArray*
	NSArray::initWithObjects(NSObject* firstObject , ...)
{
	if(firstObject)
		self->ref->addObject(firstObject);

	afor(NSObject* ,obj ,firstObject)
		self->ref->addObject(obj);
	aend
	return self;
}
NSArray*
	NSArray::arrayWithObjects(NSObject* firstObject , ...)
{
	NSArray* instance = alloc();
	if(firstObject)
		instance->ref->addObject(firstObject);

	afor(NSObject* ,obj ,firstObject)
		instance->ref->addObject(obj);
	aend
	
	instance->autorelease();

	return instance;
}
NSArray*
	NSArray::arrayWithObject(NSObject* anObject)
{
	return (NSArray*) alloc()->initWithObject(anObject)->autorelease();
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
NSArray::NSArray(NSUInteger num)
{
	ref = CCArray::arrayWithCapacity(num);
}

NSObject* 
	NSArray::objectAtIndex(NSUInteger index)
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
	return (NSArray*) alloc()->init()->autorelease();
}
void
	NSArray::dealloc()
{
	//if(self->m_bManaged == false)
	//{
	//	ref->removeAllObjects();
	//	ref->release();
	//	ref = nil;
	//}
}
void
	NSArray::objectDidUnload()
{
	self->ref->removeAllObjects();
}
/*oid
	NSArray::objectDidRecycle()
{
	_cache[--_header] = self;
	_cache_count++;
	m_uReference++;
}
void 
	NSArray::operator delete(void* pointer)
{
	if(_header > 0)
	{
		NSArray* object = (NSArray*) pointer;
		object->objectDidUnload();
		object->objectDidRecycle();
	}else{
		free(pointer);
	}
}
NSArray*
	NSArray::alloc()
{
	  NSArray* mem ; 
	if(_cache_count <= 0) 
	{
		for (NSUInteger i = 0; i< MAX_CACHE_OBJECT ;i++) _cache[i] = new NSArray();  
		_cache_count = MAX_CACHE_OBJECT; _header =0;
	}  
	mem = _cache[_header]; _header = (_header++) % MAX_CACHE_OBJECT ; --_cache_count;  
	
	if(!mem){CC_SAFE_DELETE(mem);}return mem;
}*/
BOOL
	NSArray::containsObject(NSObject* checkingObject)
{ 
	return ref->containsObject(checkingObject);
}
NSUInteger 
	NSArray::count() { return ref->count();}
NSObject* 
	NSArray::lastObject(){ return (NSObject* )ref->lastObject();}
void
	NSArray::objectDidLoad()
{
	ref = CCArray::array();
	self->copying = self;
	ref->retain();

}
vid
	NSArray::copyWithZone(NSZone* aZone)
{
	NSArray* newArray  = (NSArray*)NSArray::alloc()->init();
	nfor(NSObject* ,obj,self)
		newArray->ref->addObject(obj);
	nend

	return newArray;
}
vid
	NSArray::nextObject()
{
	if(indexedObject <= endedObejct && self->ref->data->num)
	{
		return *(indexedObject++);
	}
		return nil;
}
void
	NSArray::gotoBeginObject()
{
	if(self->ref->data->num )
	{
		indexedObject = (NSObject**)self->ref->data->arr;
		endedObejct   = (NSObject**)indexedObject + self->ref->data->num-1;
	}
}
NS_CACHE_OBJECT_INIT(NSArray)