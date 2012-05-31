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
#include <Foundation/NSString.h>
#include <Foundation/NSCopying.h>
#include <Foundation/NSZone.h>
#include <Foundation/NSFastEnumeration.h>
typedef  CCDictionary<std::string,NSObject*> CCStringDictionary;
NS_INTERFACE
	( NSDictionary , NSObject , NSCopying, NSFastEnumeration)
public:
	NS_HAS_REF( CCStringDictionary * ,ref);
	static NSDictionary*
		dictionary();
	static NSDictionary*
		dictionaryWithObjectAndKeys(NSObject*,NSString*,...);
	NSDictionary* 
		initWithObjectsAndKeys(NSObject*,NSString*,...);

	NSDictionary();
	
	inline NSObject*
		objectForKey(NSString* str)
	{
		return ref->objectForKey(str->ref->m_sString);
	}
	vid
		copyWithZone(NSZone*);
	vid
		nextObject();
	void
		gotoBeginObject();

NS_END