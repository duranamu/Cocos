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
#ifndef NSDICTIONARY_H
#define NSDICTIONARY_H
#include <cocos2d.h>
#include "NSObject.h"
#include "NSString.h"
using namespace cocos2d;
class NSDictionary :public NSObject
{
public:
	CCDictionary<std::string,NSObject*>* ref;
	static NSDictionary*
		alloc();
	static NSDictionary*
		dictionary();
	NSDictionary*
		init();
	static NSDictionary*
		dictionaryWithObjectAndKeys(NSObject*,NSString*,...);
	NSDictionary* 
		initWithObjectsAndKeys(NSObject*,NSString*,...);

		NSDictionary()
	{ref = new CCDictionary<std::string,NSObject*>();}
	inline bool
		setObject_forKey(NSObject* obj  ,NSString* str)
	{	
		if(obj && str)
			return ref->setObject(obj,str->description());
		else
			return false;
	}
	inline void
		removeObjectForKey(NSString* str)
	{
		ref->removeObjectForKey(str->description());
	}
	inline void 
		removeAllObjects()
	{
		ref->removeAllObjects();
	}
	inline NSObject*
		objectForKey(NSString* str)
	{
		return ref->objectForKey(str->description());
	}
	inline void
		autorelease()
	{
		ref->autorelease();
	}
	inline void
		retain()
	{
		ref->retain();
	}
	inline void
		release()
	{
		ref->release();
	}

	~NSDictionary()
	{
		ref->release();
	}

};
#endif