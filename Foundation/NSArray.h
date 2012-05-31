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
#include <Foundation/NSCopying.h>
#include <Foundation/NSZone.h>
#include <Foundation/NSFastEnumeration.h>
#include <stdarg.h>
NS_INTERFACE_DEBUG( NSArray , NSObject ,public NSCopying ,public NSFastEnumeration )
public:
	NS_HAS_REF(CCArray* ref);

	NSArray* 
		initWithObjects (NSObject* anObject, ...);
	NSArray*
		initWithObject(NSObject* anObject);
	static NSArray* 
		arrayWithObjects(NSObject* anObject, ...);
	static NSArray*
		arrayWithObject(NSObject* anObject);
	static NSArray*
		array();
	NS_IGNORE NSArray(){};
		 
		NSArray(NSUInteger num);
	NSObject* 
		objectAtIndex(NSUInteger index);

    NSObject* 
		randomObject();
	BOOL
		containsObject(NSObject* obj);
	NSUInteger 
		count();
	NSObject* 
		lastObject();
	inline NSUInteger
		indexOfObject(NSObject* obj){return ref->indexOfObject(obj); }
	 vid 
		 copyWithZone(NSZone*);
	vid
		nextObject();
	void
		gotoBeginObject();
	NSObject** indexedObject;
	NSObject** endedObejct;
};