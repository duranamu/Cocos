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
#include <UIKit/UIApplication.h>
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
void
	UIApplication::applicationDidUpdate(CGFloat time)
{
	if(isRighthandTracked)
	{
		UITouchPhase ability; 
		ability = touchPhaseforTime_handz(time,m_handz);
		UITouch* touch = UITouch::alloc()->initWithPhase(ability);
		CCSet* set = new CCSet(); 
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
			UIEvent* events = UIEvent::alloc()->initWithTouches_type(set ,UIEventTypeTouches);
			self->senEvent(events);
			events->release();
			set->release();
		}else if (ability == UITouchPhaseMoved )
	    {
			 touch->settimestamp(time);
			 touch->setlocation (ccp(m_handx , m_handy ));
			 UITouch* lefthand_touch = UITouch::alloc()->initWithPhase(ability);
			 lefthand_touch->settimestamp(time);
			 lefthand_touch->setlocation ( ccp( ml_handx , ml_handy ));
			 set->addObject(touch);
			 set->addObject(lefthand_touch);

			UIEvent* events = UIEvent::alloc()->initWithTouches_type(set ,UIEventTypeTouches);
			self->senEvent(events);
			events->release();
			set->release();
		}
		
	}
	trackerManager->updateTrackerSheet();
}
	UIApplication::UIApplication()
{
		isRighthandTracked = NO;
		menuTouchPhase = UITouchPhasePending;
		touchStartx = 0;
		touchStarty = 0;
		touchStartTime = 0;
		t_lasthandx = 0;
		t_lasthandy = 0;
		g_lasthandz = 0;
		self->windows = NSArray::alloc()->init();
}
void
	UIApplication::setupTracker()
{
		trackerManager =  NITrackerManager::defaultTrackerManager();
		torsoTracker =	  NITracker::trackerWithTarget_action_joint(self,NS_SELECTOR_PP   (UIApplication::predo_controller_torsoData),XN_SKEL_TORSO);

		righthandTracker =	NITracker::trackerWithTarget_action_joint(self,NS_SELECTOR_PP   (UIApplication::predo_controller_righthandData),XN_SKEL_RIGHT_HAND);

		lefthandTracker =	NITracker::trackerWithTarget_action_joint(self,NS_SELECTOR_PP   (UIApplication::predo_controller_lefthandData),XN_SKEL_LEFT_HAND);

		trackerManager->addTracker(torsoTracker);
		trackerManager->addTracker(righthandTracker);
		trackerManager->addTracker(lefthandTracker);
}
vid 
	UIApplication::predo_controller_torsoData(void* sender,vid data)
{
	_cast(UIApplication*,sender);
	_cast(CIVector*,data);
	csender->getkeyWindow()->getrootViewController()->predo_controller_torsoData (sender , data);
	cdata->release();
	return nil;
}
vid 
	UIApplication::predo_controller_righthandData(void* sender,vid data)
{
	_cast(UIApplication*,sender);
	if(!csender->isRighthandTracked) 
		csender->isRighthandTracked = true;
	_cast(CIVector*,data);
	csender->m_handz = cdata->getZ();
	csender->m_handx = cdata->getX();
	csender->m_handy = 480 - cdata->getY();
	cdata->release();
	return nil;
} 
vid
	UIApplication::predo_controller_lefthandData(void* sender , vid data)
{
	_cast(UIApplication*,sender);
	_cast(CIVector*,data);
	csender->ml_handz = cdata->getZ();
	csender->ml_handx = cdata->getX();
	csender->ml_handy = 480 - cdata->getY();
	cdata->release();
	return nil;
}
UITouchPhase 
	UIApplication::touchPhaseforTime_handz(CGFloat time, CGFloat handz)
{
	float deltahandz;
	deltahandz = g_lasthandz - handz;
	NSInteger velocity = deltahandz / time;
	velocity = (velocity >> 5);

	float deltahandzVelocity;
	deltahandzVelocity = g_lasthandzVelocity - velocity  ;
	NSInteger acceleration = deltahandzVelocity /time;
	acceleration = (acceleration >> 7);

	BOOL firstRun = !g_lasthandz ;
	g_lasthandz = handz;
	g_lasthandzVelocity = velocity;	

	if(firstRun)
	{
		return UITouchPhasePending;
	}else if( velocity >= 10 )
	{
		if( menuTouchPhase ==  UITouchPhasePending )
		{
			return menuTouchPhase = UITouchPhaseBegan;
		}else{
			return menuTouchPhase;
		}
	}else if (acceleration < 1 ){
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
	nfor(UIWindow* ,pWindow,windows)
		if(pWindow->keyWindow)
		{
			pWindow->retain();
			keyWindow = pWindow;
		}
	nend
	setupTracker();
}
void
	UIApplication::dealloc()
{
	self->keyWindow->release();
	self->keyWindow = nil;
	self->windows->release();
	self->windows = nil;
}