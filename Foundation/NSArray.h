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
#include <Foundation/Cocos2DX_framework.h>
#include <Foundation/NSCopying.h>
#include <Foundation/NSZone.h>
#include <Foundation/NSFastEnumeration.h>
#include <stdarg.h>
NS_INTERFACE( NSArray , NSObject ,NSCopying ,NSFastEnumeration )
public:
	NS_HAS_REF(CCArray* ref);
	NSArray* 
		initWithObjects (NSObject* , ...);
	NSArray*
		initWithObject(NSObject* );
	static NSArray*
		array();
	static NSArray*
		arrayWithCapacity(NSUInteger );
	    NSArray();
		 
		NSArray(NSUInteger num);
	NSObject* 
		objectAtIndex(NSUInteger index);
 
    NSObject* 
		randomObject();
	inline bool
		containsObject(NSObject* obj){ return ref->containsObject(obj);}
	inline void
		addObject(NSObject* obj){ ref->addObject(obj);}
	
	inline NSUInteger 
		count() { return ref->count();}
	inline NSObject* 
		lastObject(){ return (NSObject* )ref->lastObject();}
	inline NSUInteger
		indexOfObject(NSObject* obj){return ref->indexOfObject(obj);}
	 void
		release();
	 vid 
		 copyWithZone(NSZone*);
	
	BOOL
		removeObject(NSObject* );
	inline void
		removeLastObject();
	inline void
		removeAllObjects();
	vid
		nextObject();
	void
		gotoBeginObject();
	NSObject** indexedObject;
	NSObject** endedObejct;
};