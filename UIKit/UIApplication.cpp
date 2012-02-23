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
#include "UIApplication.h"
#include "../AppDelegate.h"
int
   UIApplicationMain (int argc,char *argv[],NSString *principalClassName,NSString *delegateClassName
){
	AppDelegate app;
	CCApplication::sharedApplication().run();

	return 0;
}
NS_SINGLETON (UIApplication,sharedApplication);
void
	UIApplication::senEvent(UIEvent* evt)
{
	self->keyWindow->sendEvent(evt);
}
NS_STATIC_ALLOC 
	(UIApplication);
NS_INSTANCE_INIT 
	(UIApplication);
void
	UIApplication::applicationDidUpdate(CGFloat time)
{
	if(isRighthandTracked)
	{
		UITouchPhase ability; 
		ability = touchPhaseforTime_handz(time,m_handz);
		UITouch* touch = UITouch::touchWithPhase(ability);
		_set* set = new _set();
		if(ability == UITouchPhaseBegan | ability == UITouchPhaseEnded )
		{
			 touch->settimestamp(time);
			 touch->setlocation ( ccp( m_handx , m_handy ));
			 UITouch* lefthand_touch = UITouch::touchWithPhase(ability);
			 lefthand_touch->settimestamp(time);
			 lefthand_touch->setlocation ( ccp( ml_handx , ml_handy ));
			 set->addObject(lefthand_touch);
			 set->addObject(touch);
			 if( ability == UITouchPhaseBegan )
			 {
				 touchStartx = m_handx;
				 touchStarty = m_handy;
				 touchStartTime = time;
			 }
			UIEvent* events = UIEvent::eventWithTouches_type(set ,UIEventTypeTouches);
			self->senEvent(events);
			events->release();
			set->release();
		}else if (ability == UITouchPhaseMoved )
	    {
			 touch->settimestamp(time);
			 touch->setlocation (ccp(m_handx , m_handy ));
			 UITouch* lefthand_touch = UITouch::touchWithPhase(ability);
			 lefthand_touch->settimestamp(time);
			 lefthand_touch->setlocation ( ccp( ml_handx , ml_handy ));
			 set->addObject(touch);
			 set->addObject(lefthand_touch);

			 UIEvent* events = UIEvent::eventWithTouches_type(set ,UIEventTypeTouches);
			self->senEvent(events);
			events->release();
			set->release();
		}
		
	}
	trackerManager->updateTrackerSheet();
}
	UIApplication::UIApplication()
{
		trackerManager =  NITrackerManager::defaultTrackerManager();
		torsoTracker =	NITracker::trackerWithTarget_action_joint(self,ccSelector   (UIApplication::predo_controller_torsoData),XN_SKEL_TORSO);

		righthandTracker =	NITracker::trackerWithTarget_action_joint(self,ccSelector   (UIApplication::predo_controller_righthandData),XN_SKEL_RIGHT_HAND);

		lefthandTracker =	NITracker::trackerWithTarget_action_joint(self,ccSelector   (UIApplication::predo_controller_lefthandData),XN_SKEL_LEFT_HAND);

		trackerManager->addTracker(torsoTracker);
		trackerManager->addTracker(righthandTracker);
		trackerManager->addTracker(lefthandTracker);

		self->windows = NSArray::array();

		isRighthandTracked = NO;
		menuTouchPhase = UITouchPhasePending;
		touchStartx = 0;
		touchStarty = 0;
		touchStartTime = 0;
		t_lasthandx = 0;
		t_lasthandy = 0;
}
void 
	UIApplication::predo_controller_torsoData(CCNode* sender,vid data)
{
	keyWindow->getrootViewController()->predo_controller_torsoData (sender , data);
}
void 
	UIApplication::predo_controller_righthandData(CCNode* sender,vid data)
{
	if(!isRighthandTracked) 
		isRighthandTracked = true;
	_cast(CCPoint3D*,data);
	m_handz = cdata->z;
	m_handx = cdata->x;
	m_handy = 480 - cdata->y;
	cdata->release();
} 
void
	UIApplication::predo_controller_lefthandData(CCNode* sender , vid data)
{
	_cast(CCPoint3D*,data);
	ml_handz = cdata->z;
	ml_handx = cdata->x;
	ml_handy = 480 - cdata->y;
	cdata->release();
}
UITouchPhase 
	UIApplication::touchPhaseforTime_handz(cocos2d::CGFloat time, CGFloat handz)
{
	float deltahandz;
	deltahandz = g_lasthandz - handz;
	g_lasthandz = handz;
	NSInteger velocity = deltahandz / time;
	velocity = (velocity >> 5);

	float deltahandzVelocity;
	deltahandzVelocity = g_lasthandzVelocity - velocity  ;
	g_lasthandzVelocity = velocity;	
	NSInteger acceleration = deltahandzVelocity /time;
	acceleration = (acceleration >>6);

	if(velocity > 30 & acceleration < 5)
	{		
		if( menuTouchPhase ==  UITouchPhasePending )
		{
			return menuTouchPhase = UITouchPhaseBegan;
		}else{
			return menuTouchPhase;
		}
	}else if (velocity < -10 & acceleration > 5){
		if(menuTouchPhase == UITouchPhaseMoved)
		{
			return menuTouchPhase = UITouchPhaseEnded;
		}else{
			return menuTouchPhase;
		}
	}else{
		if( menuTouchPhase ==  UITouchPhasePending)
		{
			return UITouchPhasePending;
		}else if (menuTouchPhase ==  UITouchPhaseBegan){
			return menuTouchPhase =  UITouchPhaseMoved;
		}else if (menuTouchPhase ==  UITouchPhaseMoved){
			return menuTouchPhase ;
		}else{
			return menuTouchPhase =  UITouchPhasePending;
		}
	}
}
void
	UIApplication::addWindow(UIWindow* window)
{
	self->windows->addObject(window);
}
void
	UIApplication::selectKeyWindow()
{
	For(UIWindow* ,pWindow,windows)
		if(pWindow->keyWindow)
		{
			keyWindow = pWindow;
		}
	forCCEnd
}