/****************************************************************************

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
#include "UIImageView.h"
UIImageView*
	UIImageView::viewWithImage(UIImage* image)
{
	UIImageView* pimageView = new UIImageView(image);

	if(!pimageView)
	{
		CC_SAFE_DELETE(pimageView);
	}

	return pimageView;
}
UIImageView::UIImageView(UIImage* image)
{
	sprite = CCSprite::spriteWithTexture(image);
};
UIImageView*
	UIImageView::viewWithTexture(CCTexture2D* image)
{
	UIImageView* pimageView = new UIImageView(image);

	if(!pimageView)
	{
		CC_SAFE_DELETE(pimageView);
	}

	return pimageView;
}
UIImageView::UIImageView(CCTexture2D* image)
{
	sprite = CCSprite::spriteWithTexture(image);
};
UIImageView*	
	UIImageView::viewWithFile(const char* path )
{
	UIImageView* pimageView = new UIImageView();

	if(!pimageView)
	{
		CC_SAFE_DELETE(pimageView);
	}else{
		pimageView->sprite =CCSprite::spriteWithFile(path);
		pimageView->sprite->retain();
	}

	return pimageView;
}