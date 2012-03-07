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
#include <Foundation/NSObjCRuntime.h>
#include <Foundation/Cocos2DX_framework.h>
#include <Foundation/NSObject.h>
#include <Foundation/NSString.h>
enum {
NSDataReadingMappedIfSafe = 1UL << 0,
NSDataReadingUncached = 1UL << 1,
NSDataReadingMappedAlways = 1UL << 3,
};
typedef NSUInteger NSDataReadingOptions;
enum {
NSDataWritingAtomic = 1UL << 0,
NSDataWritingFileProtectionNone = 0x10000000,
NSDataWritingFileProtectionComplete = 0x20000000,
NSDataWritingFileProtectionCompleteUnlessOpen = 0x30000000,
NSDataWritingFileProtectionCompleteUntilFirstUserAuthentication = 0x40000000,
NSDataWritingFileProtectionMask = 0xf0000000,
};
typedef NSUInteger NSDataWritingOptions;
enum {
NSDataSearchBackwards = 1UL << 0,
NSDataSearchAnchored = 1UL << 1
};
typedef NSUInteger NSDataSearchOptions;
NS_INTERFACE(NSData,NSObject)
	NS_SYNTHESIZE( NSString* ,dataPath);
	NSData*
		initWithBytes_length(vid ,NSUInteger );
	NSData*
		initWithBytesNoCopy_length(vid ,NSUInteger );
	NSData*
		initWithContentsOfFile(NSString *);

	static NSData*
		dataWithContentsOfFile(NSString *);
	static NSData*
		dataWithBytes_length(vid,NSUInteger);
	static NSData*
		dataWithBytesNoCopy_length(vid,NSUInteger);
	const void *
		bytes();
	NSUInteger
		length();
protected:
	vid _bytes;
	NSUInteger _length;
	
};