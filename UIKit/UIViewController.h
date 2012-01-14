/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

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
#include "NIKit\NIKit.h"
class UIViewController :public CCNode ,UIResponder
{
public:
	UIViewController()
	{
		view = new UIView();
		followView = new UIView();
		trackerManager =  NITrackerManager::defaultTrackerManager();m

		torsoTracker =	NITracker::trackerWithTarget_action_joint(this,ccSelector   (UIViewController::predo_controller_torsoData),XN_SKEL_TORSO);

		righthandTracker =	NITracker::trackerWithTarget_action_joint(this,ccSelector   (UIViewController::predo_controller_righthandData),XN_SKEL_RIGHT_HAND);

		trackerManager->addTracker(torsoTracker);
		trackerManager->addTracker(righthandTracker);

		isRighthandTracked = false;
	}
void 
	viewDidLoad(void){}
void 
	viewDidRender(CCLayer* host );
virtual void 
	viewDidUpdate(cocos2d::ccTime ){};
void 
	viewReloadData(CCArray* toShow);
CCSprite*  
	renderTargetforHost();
virtual void 
	touchesBegin_withEvent(CCSet* touches ,UIEvent* events) {};
virtual void 
	touchesMoved_withEvent(CCSet* touches ,UIEvent* events) {};
virtual void 
	touchesEnded_withEvent(CCSet* touches ,UIEvent* events) {};
virtual void 
	controller_torsoData(CCNode* ,CCPoint3D*){};
virtual void 
	controller_righthandData(CCNode* ,CCPoint3D*){};
void 
	predo_controller_torsoData(CCNode* ,void*);
void 
	predo_controller_righthandData(CCNode* ,void*);
bool 
	clickableforTime_handz(cocos2d::ccTime time, float handz);
void 
	controllerDidUpdate(cocos2d::ccTime time);
void 
	UIViewController::touchforHandpoint_view(int , int ,UIView* );
public:
	UIView* view;
	UIView* followView;
	UIView* clickView;
	NITrackerManager* trackerManager;
	NITracker* torsoTracker;
	NITracker* righthandTracker;
protected:
	float g_lasthandz;
	float g_lasthandzVelocity;
	float m_handz;
	float m_handx;
	float m_handy;
	float m_torsox;
	float m_torsoy;
	bool isRighthandTracked;
};
#endif