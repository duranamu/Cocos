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
   UIApplicationMain (int argc,char *argv[],NSString *principalClassName,NSString* delegateClassName
){
	AppDelegate app;
	CCApplication::sharedApplication().run();
	return 0;
}
NS_SINGLETON (UIApplication,sharedApplication);
void
	UIApplication::sentEvent(UIEvent* evt)
{
	self->keyWindow->sendEvent(evt);
}
void
	UIApplication::applicationDidUpdate(CGFloat time)
{
	if(false)
	if(isRighthandTracked)
	{
		UITouchPhase ability; 
		ability = touchPhaseforTime_handz(time,rightHandz);
		UITouch* touch = UITouch::alloc()->initWithPhase(ability);
		NSSet* set = new NSSet(); 
		if(ability == UITouchPhaseBegan | ability == UITouchPhaseEnded )
		{
			 touch->settimestamp(time);
			 touch->setlocation (ccp( rightHandx , rightHandy ));
			 UITouch* lefthand_touch = UITouch::touchWithPhase(ability);
			 lefthand_touch->settimestamp(time);
			 lefthand_touch->setlocation ( ccp( leftHandx , leftHandy ));
			 set->addObject(lefthand_touch);
			 set->addObject(touch);
			 if( ability == UITouchPhaseBegan )
			 {
				 touchStartx = rightHandx;
				 touchStarty = rightHandy;
				 touchStartTime = time;
			 }
			UIEvent* events = UIEvent::alloc()->initWithTouches_type(set ,UIEventTypeTouches);
			self->sentEvent(events);
			events->release();
			set->release();
		}else if (ability == UITouchPhaseMoved )
	    {
			 touch->settimestamp(time);
			 touch->setlocation (ccp(rightHandx , rightHandy ));
			 UITouch* lefthand_touch = UITouch::alloc()->initWithPhase(ability);
			 lefthand_touch->settimestamp(time);
			 lefthand_touch->setlocation(ccp(leftHandx , leftHandy ));
			 set->addObject(touch);
			 set->addObject(lefthand_touch);
			UIEvent* events = UIEvent::alloc()->initWithTouches_type(set ,UIEventTypeTouches);
			self->sentEvent(events);
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
		rightHandShadowz = 0;
		self->windows = NSMutableArray::alloc()->init();
}
void
	UIApplication::setupTracker()
{
		trackerManager =  NITrackerManager::defaultTrackerManager();
	trackerManager->addTracker(
		NITracker::trackerWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::predo_controller_torsoData),XN_SKEL_TORSO
		));
	trackerManager->addTracker(
		NITracker::trackerWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::predo_controller_righthandData),XN_SKEL_RIGHT_HAND
		));
	trackerManager->addTracker(
		NITracker::trackerWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::predo_controller_lefthandData),XN_SKEL_LEFT_HAND
		));
	trackerManager->addTracker(
		NITracker::trackerWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::sender_neckData),XN_SKEL_NECK
		));
	trackerManager->addTracker(
		NITracker::trackerWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::sender_rightElbowData),XN_SKEL_RIGHT_ELBOW
		));
	trackerManager->addTracker(
		NITracker::trackerWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::sender_rightCollarData),XN_SKEL_RIGHT_COLLAR
		));
}
vid
	UIApplication::sender_rightCollarData(vid sender,vid data)
{
	NSCAST(UIApplication*,sender);
	NSCAST(CIVector*,data);
	csender->setrightCollarx(cdata->getX());
	csender->setrightCollary(480 - cdata->getY());
	csender->setrightCollarz(cdata->getZ());
	cdata->release();
	return nil;
}
vid
	UIApplication::sender_rightElbowData(vid sender,vid data)
{
	NSCAST(UIApplication*,sender);
	NSCAST(CIVector*,data);
	csender->setrightElbowx(cdata->getX());
	csender->setrightElbowy(480 - cdata->getY());
	csender->setrightElbowz(cdata->getZ());
	cdata->release();
	return nil;
}
vid
	UIApplication::sender_neckData(vid sender,vid data)
{
	NSCAST(UIApplication*,sender);
	NSCAST(CIVector*,data);
	csender->setneckx(cdata->getX());
	csender->setnecky(480 - cdata->getY());
	csender->setneckz(cdata->getZ());
	cdata->release();
	return nil;
}
vid 
	UIApplication::predo_controller_torsoData(void* sender,vid data)
{
	NSCAST(UIApplication*,sender);
	NSCAST(CIVector*,data);
	csender->settorsox(cdata->getX());
	csender->settorsoy(cdata->getY());
	csender->getkeyWindow()->getrootViewController()->predo_controller_torsoData (sender , data);
	cdata->release();
	return nil;
}
vid 
	UIApplication::predo_controller_righthandData(void* sender,vid data)
{
	NSCAST(UIApplication*,sender);
	if(!csender->isRighthandTracked) 
		csender->isRighthandTracked = true;
	NSCAST(CIVector*,data);
	csender->rightHandz = cdata->getZ();
	csender->rightHandx = cdata->getX();
	csender->rightHandy = 480 - cdata->getY();
	cdata->release();
	return nil;
} 
vid
	UIApplication::predo_controller_lefthandData(void* sender , vid data)
{
	NSCAST(UIApplication*,sender);
	NSCAST(CIVector*,data);
	csender->leftHandz = cdata->getZ();
	csender->leftHandx = cdata->getX();
	csender->leftHandy = 480 - cdata->getY();
	cdata->release();
	return nil;
}
UITouchPhase 
	UIApplication::touchPhaseforTime_handz(CGFloat time, CGFloat handz)
{
	float deltahandz;
	deltahandz = rightHandShadowz - handz;
	NSInteger velocity = deltahandz / time;
	velocity = (velocity >> 5);

	float deltahandzVelocity;
	deltahandzVelocity = rightHandShadowzVelocity - velocity  ;
	NSInteger acceleration = deltahandzVelocity /time;
	acceleration = (acceleration >> 7);

	BOOL firstRun = !rightHandShadowz ;
	rightHandShadowz = handz;
	rightHandShadowzVelocity = velocity;	

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