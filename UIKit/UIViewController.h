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
#ifndef UIVIEWCONTROLLER_H
#define UIVIEWCONTROLLER_H
#include "..\Cocos\Cocos.h"
#include "UIView.h"
#include "UIResponder.h"
#include "UIImageView.h"
#include "NIKit\NIKit.h"
#ifndef TOUCH_FUNC
#define TOUCH_FUNC

#endif
class UIViewController :public CCNode ,UIResponder
{
public:
	UIViewController()
	{
		view = new UIView();
		followView = new UIView();
		movableView = new UIView();
		righthand_clicked_marker = UIImageView::viewWithFile(nss("stars.png"));

		trackerManager =  NITrackerManager::defaultTrackerManager();
		torsoTracker =	NITracker::trackerWithTarget_action_joint(this,ccSelector   (UIViewController::predo_controller_torsoData),XN_SKEL_TORSO);

		righthandTracker =	NITracker::trackerWithTarget_action_joint(this,ccSelector   (UIViewController::predo_controller_righthandData),XN_SKEL_RIGHT_HAND);

		lefthandTracker =	NITracker::trackerWithTarget_action_joint(this,ccSelector   (UIViewController::predo_controller_lefthandData),XN_SKEL_LEFT_HAND);

		trackerManager->addTracker(torsoTracker);
		trackerManager->addTracker(righthandTracker);
		trackerManager->addTracker(lefthandTracker);

		isRighthandTracked = false;
		menuTouchPhase = UITouchPhasePending;
		touchStartx = 0;
		touchStarty = 0;
		touchStartTime = 0;
		t_lasthandx = 0;
		t_lasthandy = 0;
	}
void 
	viewDidLoad(void){}
void 
	viewDidUnload(void){}
void 
	viewDidRender(CCLayer* host );
virtual void 
	viewDidUpdate(cocos2d::ccTime ){};
void 
	viewReloadData(NSArray* toShow);
CCSprite*  
	renderTargetforHost();
virtual void 
	touchesBegin_withEvent(CCSet* touches ,UIEvent* events);
virtual void 
	touchesMoved_withEvent(CCSet* touches ,UIEvent* events);
virtual void 
	touchesEnded_withEvent(CCSet* touches ,UIEvent* events) ;
virtual void 
	controller_torsoData(CCNode* ,CCPoint3D*){};
virtual void 
	controller_righthandData(CCNode* ,CCPoint3D*){};
void 
	predo_controller_torsoData(CCNode* ,void*);
void 
	predo_controller_righthandData(CCNode* ,void*);
void 
	predo_controller_lefthandData(CCNode* ,void*);
UITouchPhase 
	touchPhaseforTime_handz(cocos2d::ccTime time, float handz);
void 
	controllerDidUpdate(cocos2d::ccTime time);
public:
	UIView* view;
	UIView* followView;
	UIView* clickView;
	UIView* movableView;
	UIView* watchVariableView;

	UIView* righthand_clicked_marker;

	NITrackerManager* trackerManager;
	NITracker* torsoTracker;
	NITracker* righthandTracker;
	NITracker* lefthandTracker;
protected:
	float g_lasthandz;
	float g_lasthandzVelocity;
	float m_handz;
	float m_handx;
	float m_handy;
	float gl_lasthandz;
	float gl_lasthandzVelocity;
	float ml_handz;
	float ml_handx;
	float ml_handy;
	float m_torsox;
	float m_torsoy;
	bool isRighthandTracked;
	UITouchPhase menuTouchPhase;
	float touchStartx;
	float touchStarty;
	ccTime touchStartTime;

	float t_lasthandx;
	float t_lasthandy;
	bool newTouchSession;
};
#endif