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
NS_CLASS NSDirectoryEnumerator;
NS_INTERFACE(NSFileManager ,NSObject)
	static NSFileManager*
		defaultManager();
	NSDirectoryEnumerator* 
		enumeratorAtPath(NSString* path);
	 NSString * currentDirectoryPath();
protected:	
NS_END
NS_DROP_EXTERN NSString * const NSFileEntry;

NS_DROP_EXTERN NSString * const NSFileType;
NS_DROP_EXTERN NSString * const NSFileTypeRegular;
NS_DROP_EXTERN NSString * const NSFileTypeDirectory;
NS_DROP_EXTERN NSString * const NSFileTypeSymbolicLink;

NS_DROP_EXTERN NSString * const NSFileTypeCharacterSpecial;
NS_DROP_EXTERN NSString * const NSFileTypeBlockSpecial;

NS_DROP_EXTERN NSString * const NSFileTypeSocket;

NS_DROP_EXTERN NSString * const NSFileTypeUnknown;

NS_DROP_EXTERN NSString * const NSFileSize;
NS_DROP_EXTERN NSString * const NSFileModificationDate;
NS_DROP_EXTERN NSString * const NSFileOwnerAccountName;
NS_DROP_EXTERN NSString * const NSFileGroupOwnerAccountName;

NS_DROP_EXTERN NSString * const NSFilePosixPermissions;
NS_DROP_EXTERN NSString * const NSFileReferenceCount;
NS_DROP_EXTERN NSString * const NSFileIdentifier;
NS_DROP_EXTERN NSString * const NSFileDeviceIdentifier;

NS_DROP_EXTERN NSString * const NSFileSystemNumber;
NS_DROP_EXTERN NSString * const NSFileSystemSize;
NS_DROP_EXTERN NSString * const NSFileSystemFreeSize;