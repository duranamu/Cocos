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
#include <Foundation/NSData.h>
const vid 
	NSData::bytes()
{
	return self->_bytes;
}
NSUInteger
	NSData::length()
{
	return self->_length;
}
NSData*
	NSData::initWithBytes_length(vid bytes ,NSUInteger length)
{
	self->_length = length;
	self->_bytes = malloc(sizeof(char)*length);
	memcpy(self->_bytes,bytes,sizeof(char)*length);

	return self;
}
NSData*
	NSData::dataWithBytes_length(vid bytes ,NSUInteger length)
{
	return alloc()->initWithBytes_length(bytes,length);
}
NSData*
	NSData::initWithBytesNoCopy_length(vid bytes ,NSUInteger length)
{
	self->_length = length;
	self->_bytes = bytes;
	return self;
}
NSData*
	NSData::dataWithBytesNoCopy_length(vid bytes ,NSUInteger length)
{
	return alloc()->initWithBytesNoCopy_length(bytes,length);
}
void
	NSData::dealloc()
{
	free(self->_bytes);
	if(dataPath)
		remove(dataPath->cStringUsingEncoding(NSASCIIStringEncoding));
}
NSData*
	NSData::initWithContentsOfFile(NSString* filePath)
{
	char* dataBytes = readFileBytes(filePath->cStringUsingEncoding(NSASCIIStringEncoding));
	self->_bytes = dataBytes;
	self->_length = strlen(dataBytes);
	self->dataPath = filePath;
	filePath->retain();
	return self;
}
NSData*
	NSData::dataWithContentsOfFile(NSString* filePath)
{
	return (NSData*) alloc()->initWithContentsOfFile(filePath)->autorelease();
}