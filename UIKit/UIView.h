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
#include <Foundation/Foundation.h>
#include <UIKit/UIResponder.h>
#include <UIKit/UITouch.h>
#include <Foundation/NSIndexPath.h>
#include <UIKit/UITapGestureRecognizer.h>
NS_INTERFACE_INIT_SPEC(UIView , UIResponder )
UIView*
	init();
	UIView();
UIView*
	anyView();
void
	addSubView(UIView* view);
virtual void 
	viewDidRender(CCLayer* hostLayer);
virtual void 
	reloadData(NSMutableArray* toShow) { };
 void 
	followPlayer(CIVector*);
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

	NS_SYNTHESIZE(NSMutableArray* ,subviews);
	NS_SYNTHESIZE_RETAIN (CCNode* , node );
	NSActionTarget* listener;
	SEL_PP  selector;
	NS_SYNTHESIZE_RETAIN( NSIndexPath* , indexPath);
	UIView* contentView;
	UIGestureRecognizer* m_pRecognizer;
	NSMutableArray* gestureRecognizers;
	BOOL hidden;
	NS_SYNTHESIZE(UIView*,superview);
};