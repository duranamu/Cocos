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
#include <Foundation/NSSet.h>
#include <Foundation/NSMutableArray.h>
NSSet*
	NSSet::initWithArray(NSMutableArray* array)
{
	nfor(NSObject* ,obj,array)
		ref->addObject(obj);
	nend
	return self;
}
NSSet*
	NSSet::setWithArray(NSMutableArray* array)
{
	return (NSSet*) alloc()->initWithArray(array)->autorelease();
}
NSSet*
	NSSet::initWithObjects(NSObject* firstObject ,...)
{
	if(firstObject)
		self->ref->addObject(firstObject);

	afor(NSObject* ,obj,firstObject)
		self->ref->addObject(obj);
	aend

	return self;
}
NSSet*
	NSSet::setWithObjects(NSObject* firstObject ,...)
{
	NSSet* set = alloc();

	if(set)
	{
		if(firstObject)
			set->ref->addObject(firstObject);
		afor(NSObject*,obj,firstObject)
			set->ref->addObject(obj);
		aend
		set->autorelease();
	}
	return set;
}
void
	NSSet::dealloc()
{
	/*if(self->ref) self->ref->release();
	self->ref = nil;*/
}
void
	NSSet::objectDidLoad()
{
	
}
void
	NSSet::objectDidUnload()
{
	nfor(NSObject*,obj,self)
		self->ref->removeObject(obj);
	nend
}
void
	NSSet::gotoBeginObject()
{
	iterator = self->ref->begin();
}
vid
	NSSet::nextObject()
{
	if(iterator != self->ref->end())
	if(*iterator)
	{
		return *(iterator++);
	}
	return nil;
}
vid
	NSSet::copyWithZone(NSZone* zone)
{
	return  alloc()->initWithSet(self);
}
	NSSet::NSSet()
{
	self->ref = new CCSet();
}
NSMutableArray*
	NSSet::allObjects()
{
	NSMutableArray* allobj = NSMutableArray::arrayWithCapacity(2);

	nfor(NSObject* ,obj,self)
		allobj->addObject(obj);
	nend
	
	return allobj;
}
NSSet*
	NSSet::initWithSet(NSSet* set)
{
	nfor(NSObject* ,obj,set)
		self->ref->addObject(obj);
	nend
	return self;
}
NSSet*
	NSSet::setWithSet(NSSet* set)
{
	return (NSSet*) alloc()->initWithSet(set)->autorelease();
}
NSSet*
	NSSet::initWithObject(NSObject* obj)
{
	self->ref->addObject(obj);
	return self;
}
NSSet*
	NSSet::setWithObject(NSObject* obj)
{
	return (NSSet*) alloc()->initWithObject(obj)->autorelease();
}
NSSet*
	NSSet::setByAddingArray(NSMutableArray* array)
{
	NSSet* newSet = NSSet::setWithSet(self);
	nfor(NSObject*,obj,array)
		newSet->ref->addObject(obj);
	nend;
	return newSet; 
}
NSSet*
	NSSet::setByAddingObject(NSObject* obj)
{
	NSSet* newSet = NSSet::setWithSet(self);
	newSet->ref->addObject(obj);
	return newSet;
}
NSSet*
	NSSet::setByAddingObjectsFromSet(NSSet* set)
{
	NSSet* newSet = NSSet::setWithSet(self);
	nfor(NSObject*,obj,set)
		newSet->ref->addObject(obj);
	nend
	return newSet;
}
NSSet*
	NSSet::setByAddingObjectsFromArray(NSMutableArray* array)
{
	NSSet* newSet = NSSet::setWithSet(self);
	nfor(NSObject*,obj,array)
		newSet->ref->addObject(obj);
	nend
	return newSet;
}
NSUInteger 
	NSSet::count()
{
	return (NSUInteger)self->ref->count();
}
BOOL
	NSSet::containsObject(NSObject* obj)
{
	return self->ref->containsObject(obj);
}
void
	NSSet::makeObjectsPerformSelector(SEL aSelector)
{
	nfor(NSSelectorProtocol* ,listener ,self)
		(listener->*aSelector)();
	nend
	return;
}
void
	NSSet::makeObjectsPerformSelector_withObject(SEL_P aSelector,NSObject* obj)
{
	nfor(NSSelectorProtocol*,listener,self)
		(listener->*aSelector)(obj);
	nend;
}
BOOL
	NSSet::isSubsetOfSet(NSSet* set)
{
	BOOL sure = true;
	nfor(NSObject*,obj,self)
		if(!set->containsObject(obj))
		{
			sure =false;
		}
	nend
	return sure;
}
BOOL
	NSSet::intersectsSet(NSSet* set)
{
	BOOL sure = false;
	nfor(NSObject*,obj,self)
		if(set->containsObject(obj))
		{
			sure =true;
		}
	nend
	return sure;
}
BOOL
	NSSet::isEqualToSet(NSSet* set)
{
	return self->isSubsetOfSet(set) && set->isSubsetOfSet(self);
}
NSObject*
	NSSet::anyObject()
{
	return (NSObject*)ref->anyObject();
}
void
	NSSet::addObject(NSObject* anObject)
{
	ref->addObject(anObject);
}
NS_CACHE_OBJECT_INIT(NSSet);