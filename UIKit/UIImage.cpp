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
#include <UIKit/UIImage.h>
UIImage*
	UIImage::initWithData_format_pixel_size(const void* data ,CCTexture2DPixelFormat format,CCSize size)
{
		ref = new CCTexture2D();
		ref->initWithData(data ,CCTexture2DPixelFormat::kCCTexture2DPixelFormat_RGB888,
		size.width,size.height,size);
		self->imagePath = NSString::alloc()->init();
	return self; 
}
UIImage*
	UIImage::imageWithData_format_pixel_size(const void* data ,CCTexture2DPixelFormat format,CCSize size)
{
	return alloc()->initWithData_format_pixel_size(data,format,size);
}
UIImage*
	UIImage::initNamed(NSString* fileName)
{
	char* CStringFileName = (char*)fileName->cStringUsingEncoding(NSASCIIStringEncoding);
	ref = new CCTexture2D();
	CCImage* ccimage = new CCImage();
	ccimage->initWithImageFile(CStringFileName);
	self->imagePath = fileName;
	fileName->retain();
	ref->initWithImage(ccimage);
	return self;
}
UIImage*
	UIImage::imageNamed(NSString* fileName)	
{
	//autorelease to be added
	return alloc()->initNamed(fileName);
}
void
	UIImage::dealloc()
{
	ref->release();
	self->ref = nil;
	self->imagePath->release();
	self->imagePath = nil;
}
UIImage*
	UIImage::imageWithData(NSData* data)
{
	//autorelease to be added
	return alloc()->initWithData(data);
}
UIImage*
	UIImage::initWithData(NSData* data)
{
	ref = new CCTexture2D();
	CCImage* ccimage = new CCImage();
	ccimage->initWithImageFile(data->getdataPath()->cStringUsingEncoding(NSASCIIStringEncoding));
	ref->initWithImage(ccimage);
	return self;
}
CCTexture2D*
	UIImage::getCCTexture2D(){return ref;}
CGImage*
	UIImage::CGImage(){ return CCTextureCache::sharedTextureCache()->addImage(imagePath->cStringUsingEncoding(NSASCIIStringEncoding)); }
