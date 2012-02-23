/****************************************************************************
	UIKit OpenSource Project
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
#ifndef UIVIEWCONTROLLER_H
#define UIVIEWCONTROLLER_H
#include <Cocos\Cocos.h>
#include "UIView.h"
#include "UIResponder.h"
#include "UIImageView.h"
#include "NIKit\NIKit.h"
#ifndef TOUCH_FUNC
#define TOUCH_FUNC

#endif
class UIViewController :public CCNode , public UIResponder ,public UIView ,public NSObject
{
public:
	UIViewController()
	{
		self->view = new UIView();
		followView = new UIView();
		movableView = new UIView();
	//	righthand_clicked_marker = UIImageView::viewWithFile(_s("stars.png"));
	}
virtual void 
	viewDidLoad(void){}
void 
	viewDidUnload(void){}
void 
	viewDidRender(CCLayer* host );
virtual void 
	viewDidUpdate(cocos2d::CGFloat ){};
void 
	viewReloadData(NSArray* toShow);
CCSprite*  
	renderTargetforHost();
virtual void 
	touchesBegan_withEvent(_set* touches ,UIEvent* events);
virtual void 
	touchesMoved_withEvent(_set* touches ,UIEvent* events);
virtual void 
	touchesEnded_withEvent(_set* touches ,UIEvent* events) ;
virtual void 
	controller_torsoData(CCNode* ,CCPoint3D*){};
virtual void 
	controller_righthandData(CCNode* ,CCPoint3D*){};
virtual void 
	predo_controller_torsoData(CCNode* ,void*);
public:
	UIView* view;
	UIView* followView;
	UIView* clickView;
	UIView* movableView;
	UIView* watchVariableView;

	UIView* righthand_clicked_marker;
protected:
	
	bool isRighthandTracked;
	UITouchPhase menuTouchPhase;

	ccSynthesize
		(CGFloat ,m_torsox);
	ccSynthesize
		(CGFloat ,m_torsoy);
	float touchStartx;
	float touchStarty;
	CGFloat touchStartTime;

	float t_lasthandx;
	float t_lasthandy;
	bool newTouchSession;

	UIView* receiver ;
	ccSynthesize
		(NSString*,title);
};
#endif