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
#ifndef UIVIEW_H
#define UIVIEW_H
#include "..\Cocos\Cocos.h"
#include "UIResponder.h"
class UIView :public UIResponder
{
public:
	CCArray* membersheet;
	CCSprite* sprite;
	UIView()
	{
		membersheet =  CCArray::arrayWithCapacity(8);
		membersheet->retain();
	}
	~UIView()
	{
//		membersheet->release();
	}
UIView*
	anyView()
	{
		if(membersheet)
		{
			return (UIView*) membersheet->objectAtIndex(0);
		}
		return nil;
	}
void
	addSubView(UIView* view)
	{
		membersheet->addObject(view);
	}
virtual void 
	viewDidRender(CCLayer* hostLayer);
virtual CCSprite*
	getSprite()
	{
		return sprite;
	}
virtual void 
	setSprite(CCSprite* i_sprite)
	{
		sprite = i_sprite;
	}
 virtual void 
	 reloadData(CCArray* toShow) {};
 void 
	followPlayer(CCPoint3D*);
 void 
	touchesBegin_withEvent(CCSet* touches ,UIEvent* events) 
 {
	 
 };
};
#endif