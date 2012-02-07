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
#include "UITouch.h"
#include  "UIIndexPath.h"
#include "UITapGestureRecognizer.h"
class UIView :public UIResponder 
{
public:
	UIView()
	{
		subviews =  NSArray::array();
		subviews->retain();
		self->recognizerSheet = nil;
	}

UIView*
	anyView()
	{
		if(subviews)
		{
			return (UIView*) subviews->objectAtIndex(0);
		}
		return nil;
	}
void
	addSubView(UIView* view)
	{
		subviews->addObject(view);
		view->setsuperview(self);
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
	reloadData(NSArray* toShow) { /*if(sprite) toShow->addObject(sprite);*/};
 void 
	followPlayer(CCPoint3D*);
 void 
	touchesBegan_withEvent(NSSet*  ,UIEvent* );
 void
	 touchesMoved_withEvent(NSSet*  ,UIEvent* );
 void
	 touchesEnded_withEvent(NSSet*  ,UIEvent* ) ;
 bool 
	 canTriggerforTouch(UITouch* );
 bool
	 canTriggerforTouch_parentSprite(UITouch* touch,CCSprite* parent);
 void
	 moveByPoint(CCPoint );
 virtual BOOL 
	 pointInside_withEvent(CGPoint,UIEvent*);
 UIView *
	hitTest_withEvent(CGPoint, UIEvent *);
 virtual void
	addGestureRecognizer(UIGestureRecognizer*);
 	NSArray* subviews;
	CCSprite* sprite;
	SelectorProtocol* listener;
	SEL_CallFuncND  selector;
	ccSynthesize( UIIndexPath* , indexPath);
	UIView* contentView;
	UIGestureRecognizer* m_pRecognizer;
	NSArray* recognizerSheet;
	BOOL hidden;
	ccSynthesize(UIView*,superview);
};
#endif