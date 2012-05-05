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
#include <Foundation/NSFileManager.h>
#include <Foundation/NSPathDirectoryEnumerator.h>
NSString * const NSFileTypeDirectory = NSSTR("NSFileTypeDirectory");
NSString * const NSFileTypeRegular = NSSTR("NSFileTypeRegular");
NSString * const NSFileTypeSymbolicLink = NSSTR("NSFileTypeSymbolicLink");
NSString * const NSFileTypeSocket= NSSTR("NSFileTypeSocket");
NSString * const NSFileTypeCharacterSpecial = NSSTR("NSFileTypeCharacterSpecial");
NSString * const NSFileTypeBlockSpecial = NSSTR("NSFileTypeBlockSpecial");
NSString * const NSFileTypeUnknown = NSSTR("NSFileTypeUnknown");
NSString * const NSFileType = NSSTR("NSFileType");
NSString * const NSFileEntry = NSSTR("NSFileEntry");
#define super NSObject
NSFileManager* defaultManagerSingleton;
NSFileManager*
	NSFileManager::defaultManager()
{
	if(defaultManagerSingleton == nil)
	{
		defaultManagerSingleton = alloc()->init(); 
	}
	return defaultManagerSingleton;
}
NSDirectoryEnumerator*
	NSFileManager::enumeratorAtPath(NSString* path)
{
	return (NSDirectoryEnumerator*) NSPathDirectoryEnumerator::enumeratorWithPath(path);
}
void
	NSFileManager::dealloc()
{
}
NSString*
	NSFileManager::currentDirectoryPath()
{
	char outfilename[260];
	strcpy(outfilename,CCFileUtils::fullPathFromRelativePath(""));
	return NSSTR(outfilename);
}