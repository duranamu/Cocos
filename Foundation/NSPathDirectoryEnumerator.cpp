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
#include <Foundation/NSPathDirectoryEnumerator.h>
#include <dirent.h>
#include <Foundation/NSString.h>
#include <Foundation/NSDictionary.h>
#include <Foundation/NSFileManager.h>
#define  super NSDirectoryEnumerator
void
	NSPathDirectoryEnumerator::gotoBeginObject()
{
	self->directoryIndex = 0;
	self->directory->gotoBeginObject();
}
vid
	NSPathDirectoryEnumerator::nextObject()
{
	self->directoryIndex++;
	NSDictionary* dict = (NSDictionary*)self->directory->nextObject();
	if(nil == dict)
	{
		return nil;
	}else{
		self->currentObject = dict;
		return dict->objectForKey(NSFileEntry);
	}
}
NSPathDirectoryEnumerator*
	NSPathDirectoryEnumerator::initWithPath(NSString * path)
{
		self->directoryIndex = 0;
		self->directory = NSMutableArray::alloc()->init();
		struct dirent *directoryEntry;
	    DIR *directoryRef;
		directoryRef = opendir(path->cStringUsingEncoding(NSASCIIStringEncoding));
		while((directoryEntry = readdir(directoryRef)))
		{
			if(directoryEntry->d_name[0] == '.')
			{
				continue;
			}
			NSString* fileType ;
			if(S_ISREG(directoryEntry->d_type))
			{
				fileType = NSFileTypeRegular;
			}else if(S_ISDIR(directoryEntry->d_type))
			{
				fileType = NSFileTypeDirectory;
			}else if(S_ISCHR(directoryEntry->d_type))
			{
				fileType = NSFileTypeCharacterSpecial;
			}else if(S_ISBLK(directoryEntry->d_type))
			{
				fileType = NSFileTypeBlockSpecial;
			}else if(S_ISSOCK(directoryEntry->d_type))
			{
				fileType = NSFileTypeSocket;
			}
			NSDictionary* attributefile = NSDictionary::alloc()->initWithObjectsAndKeys(
				fileType ,NSFileType,NSSTR(directoryEntry->d_name),NSFileEntry,nil);
			self->directory->addObject(attributefile);
			attributefile->release();
		}
		closedir(directoryRef);
	return self;
}
NSPathDirectoryEnumerator*
	NSPathDirectoryEnumerator::enumeratorWithPath(NSString* path)
{
	return (NSPathDirectoryEnumerator*) alloc()->initWithPath(path)->autorelease();
}
NSDictionary*
	NSPathDirectoryEnumerator::fileAttributes()
{
	return  self->currentObject;
}
void
	NSPathDirectoryEnumerator::dealloc()
{

}
