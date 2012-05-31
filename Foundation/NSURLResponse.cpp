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
#include <Foundation/NSURLResponse.h>
NSURLResponse*
	NSURLResponse::initWithURL_MIMEType_expectedContentLength_textEncodingName
	(NSString* url,NSString* MIMEType ,long long expectedContentLength ,NSString* encoding)
{
	url->retain();
	MIMEType->retain();
	encoding->retain();
	self->_url = url;
	self->_mimeType = MIMEType;
	self->_expectedContentLength = expectedContentLength;
	self->_encoding = encoding;
	return self;
}
void
	NSURLResponse::dealloc()
{
	//	self->_url->release();
		self->_mimeType->release();
		self->_encoding->release();
}
NSString*
	NSURLResponse::URL()
{
	return self->_url;
}
NSString *
	NSURLResponse::MIMEType()
{
	return self->_mimeType;
}
long long 
	NSURLResponse::expectedContentLength()
{
	return self->_expectedContentLength;
}
NSString * 
	NSURLResponse::textEncodingName()
{
	return self->_encoding;
}
//todo
NSString * 
	NSURLResponse::suggestedFilename()
{
	return nil;
}