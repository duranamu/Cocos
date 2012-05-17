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
#include <Foundation/NSObjCRuntime.h>
#include <Foundation/NSErro.h>
NS_CLASS NSData;
typedef NSUInteger NSStringEncoding;
typedef NSUInteger NSStringCompareOptions;
NS_INTERFACE_DEBUG(NSString ,NSObject,public NSObjectProtocol)
	NS_HAS_REF(CCString* ref);
public:
	NS_IGNORE NSString(){};

	virtual NSString*
		description();
	NSString*
		initWithData_encoding(NSData * ,NSStringEncoding);
	NSString*
		initWithBytes_length_encoding(const vid  bytes ,NSUInteger length,NSStringEncoding encoding);
	NSString*
		initWithCString_encoding(const char* cString ,NSStringEncoding encoding);
	static NSString*
		stringWithCString_encoding(const char* cString ,NSStringEncoding encoding);
	static NSString*
		stringWithString(NSString* string);
	static NSString*
		 stringWithFormat(NSString* format,...);
	 NSString*
		initWithContentOfFile_encoding_erro(NSString* path ,NSStringEncoding enc , NSError** error);
	 static NSString*
		stringWithContentOfFile_encoding_erro(NSString* path ,NSStringEncoding enc , NSError** error);
	 NSString*
		initWithString(NSString* string );
	 NSString*
		 initWIthFormat(NSString* format,...);
	 NSString*
		 initWithFormat_locale_arguments(NSString* format ,vid local ,va_list arguments);
	 NSUInteger
		 length();
	 const char *
		cStringUsingEncoding(NSStringEncoding encoding);
	 NSComparisonResult
			compare(NSString * aString);
	protected:
	NS_SYNTHESIZE
		(NSStringEncoding ,_encoding);
NS_END
enum {
    NSASCIIStringEncoding = 1,
    NSNEXTSTEPStringEncoding = 2,
    NSJapaneseEUCStringEncoding = 3,
    NSUTF8StringEncoding = 4,
    NSISOLatin1StringEncoding = 5,
    NSSymbolStringEncoding = 6,
    NSNonLossyASCIIStringEncoding = 7,
    NSShiftJISStringEncoding = 8,
    NSISOLatin2StringEncoding = 9,
    NSUnicodeStringEncoding = 10,
    NSWindowsCP1251StringEncoding = 11,
    NSWindowsCP1252StringEncoding = 12,
    NSWindowsCP1253StringEncoding = 13,
    NSWindowsCP1254StringEncoding = 14,
    NSWindowsCP1250StringEncoding = 15,
    NSISO2022JPStringEncoding = 21,
    NSMacOSRomanStringEncoding = 30,
    NSUTF16StringEncoding = NSUnicodeStringEncoding,
    NSUTF16BigEndianStringEncoding = 0x90000100,
    NSUTF16LittleEndianStringEncoding = 0x94000100,
    NSUTF32StringEncoding = 0x8c000100,
    NSUTF32BigEndianStringEncoding = 0x98000100,
    NSUTF32LittleEndianStringEncoding = 0x9c000100,
    NSProprietaryStringEncoding = 65536
};
enum {
   NSCaseInsensitiveSearch = 1,
   NSLiteralSearch = 2,
   NSBackwardsSearch = 4,
   NSAnchoredSearch = 8,
   NSNumericSearch = 64,
   NSDiacriticInsensitiveSearch = 128,
   NSWidthInsensitiveSearch = 256,
   NSForcedOrderingSearch = 512,
   NSRegularExpressionSearch = 1024
};