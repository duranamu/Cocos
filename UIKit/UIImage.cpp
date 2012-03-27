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
	UIImage::imageWithData_format_pixel_size(const void* data ,CCTexture2DPixelFormat format,CCSize size)
{
	UIImage* pimage = new UIImage(data,format,size);
	if(pimage)
	{
		
	}else{
		CC_SAFE_DELETE(pimage);
	}
	return pimage; 
}
UIImage*
	UIImage::imageNamed(NSString* file)
{
	UIImage* pimage = new UIImage(file->description().c_str());
	if(pimage)
	{

	}else{
		CC_SAFE_DELETE(pimage);
	}
	return pimage;
}
UIImage::UIImage(const char* file)
{
	ref = new CCTexture2D();
	CCImage* ccimage = new CCImage();
	ccimage->initWithImageFile(file);
	self->imagePath = NSSTR(file);
	ref->initWithImage(ccimage);
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
	return alloc()->initWithData(data);
}
UIImage*
	UIImage::initWithData(NSData* data)
{
	ref = new CCTexture2D();
	CCImage* ccimage = new CCImage();
	ccimage->initWithImageFile(data->getdataPath()->description().c_str());
	ref->initWithImage(ccimage);
	return self;
}