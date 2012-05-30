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
#include <NIKit/NITraceTracker.h>
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
	UIApplication::applicationDidUpdate(CGFloat deltaTime)
{
	trackerManager->updateTrackerSheet();
	if(isRighthandTracked)
	{
		UITouchPhase ability;
		UITouchPhase anotherAbility;
		UITouchSource touchSource ;
		ability = (UITouchPhase) self->righthandTracker->gettracePhase(); 
		anotherAbility = (UITouchPhase) self->lefthandTracker->gettracePhase(); 
		
		if(ability != UITouchPhasePending && anotherAbility == UITouchPhasePending)
		{
			touchSource = UITouchSourceRightHand;
		}
		else if(anotherAbility != UITouchPhasePending && ability == UITouchPhasePending)
		{
			touchSource = UITouchSourceLeftHand;
		}
		else if(ability == UITouchPhasePending && anotherAbility == UITouchPhasePending)
		{
			return ;
		}else if(anotherAbility != UITouchPhasePending && ability != UITouchPhasePending)
		{
			touchSource = (UITouchSource)( UITouchSourceLeftHand | UITouchSourceRightHand);
		}
		UITouch* touch = UITouch::alloc()->initWithPhase(ability);
		UITouch* lefthand_touch = UITouch::alloc()->initWithPhase(anotherAbility);
		NSSet* set =  NSSet::alloc()->init();
		NSTimeInterval timeMark = time(nil);

		if(touchSource & UITouchSourceRightHand)
		{
			touch->setdeltaTime(deltaTime);
			touch->settimeMark(timeMark);
			touch->setlocation (CGPointMake(rightHandx , rightHandy ));
			touch->settouchSource(UITouchSourceRightHand);
			set->addObject(touch);
		} 
		if (touchSource & UITouchSourceLeftHand)
		{
			lefthand_touch->setdeltaTime(deltaTime);
			lefthand_touch->settimeMark(timeMark);
			lefthand_touch->setlocation(CGPointMake(leftHandx , leftHandy ));
			lefthand_touch->settouchSource(UITouchSourceLeftHand);
			set->addObject(lefthand_touch);
		}
	    UIEvent* events = UIEvent::alloc()->initWithTouches_type(set ,UIEventTypeTouches);
	    self->sentEvent(events);
		events->release();
		set->release();
		touch->release();
		lefthand_touch->release();

		if(ability == UITouchPhaseEnded)
		{
			self->righthandTracker->settracePhase((NITracePhase)UITouchPhasePending);
		}
		if(anotherAbility == UITouchPhaseEnded)
		{
			self->righthandTracker->settracePhase((NITracePhase)UITouchPhasePending);
		}
	
	}
	
}	
UIApplication*
	UIApplication::init()
{
		isRighthandTracked = NO;
		menuTouchPhase = UITouchPhasePending;
		t_lasthandx = 0;
		t_lasthandy = 0;
		shadowz = 0;
		self->windows = NSMutableArray::alloc()->init();

		return self;
}
void
	UIApplication::setupTracker()
{
		trackerManager =  NITrackerManager::defaultTrackerManager();

		self->lefthandTracker = NITraceTracker::alloc()->initWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::sender_lefthandData),XN_SKEL_LEFT_HAND);
	trackerManager->addTracker(self->lefthandTracker);

		self->righthandTracker = NITraceTracker::alloc()->initWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::sender_righthandData),XN_SKEL_RIGHT_HAND);
	trackerManager->addTracker(self->righthandTracker);

	/*trackerManager->addTracker(
		NITraceTracker::alloc()->initWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::sender_torsoData),XN_SKEL_TORSO));

	trackerManager->addTracker(
		NITracker::alloc()->initWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::sender_neckData),XN_SKEL_NECK));

	trackerManager->addTracker(
		NITracker::alloc()->initWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::sender_rightElbowData),XN_SKEL_RIGHT_ELBOW));

	trackerManager->addTracker(
		NITracker::alloc()->initWithTarget_action_joint(self,
		NS_SELECTOR_PP(UIApplication::sender_rightCollarData),XN_SKEL_RIGHT_COLLAR));*/
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
	UIApplication::sender_torsoData(void* sender,vid data)
{
	NSCAST(UIApplication*,sender);
	NSCAST(CIVector*,data);
	csender->settorsox(cdata->getX());
	csender->settorsoy(cdata->getY());
	csender->getkeyWindow()->getrootViewController()->sender_torsoData (sender , data);
	cdata->release();
	return nil;
}
vid 
	UIApplication::sender_righthandData(void* sender,vid data)
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
	UIApplication::sender_lefthandData(void* sender , vid data)
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
	deltahandz = shadowz - handz;
	NSInteger velocity = deltahandz / time;
	velocity = (velocity >> 5);

	float deltahandzVelocity;
	deltahandzVelocity = shadowzVelocity - velocity  ;
	NSInteger acceleration = deltahandzVelocity /time;
	acceleration = (acceleration >> 8);

	BOOL firstRun;
		firstRun = !shadowz ;
	shadowz = handz;
	shadowzVelocity = velocity;	

	if(firstRun)
	{
		return UITouchPhasePending;
	}else if( velocity >= 20 && menuTouchPhase != UITouchPhaseBegan && menuTouchPhase != UITouchPhaseMoved )
	{
		return menuTouchPhase = UITouchPhaseBegan;
	}else if (acceleration < 1 && menuTouchPhase == UITouchPhaseMoved){
		self->shadowz = 0;
		self->shadowzVelocity = 0;
		return menuTouchPhase = UITouchPhaseEnded;
	}else if(menuTouchPhase == UITouchPhaseBegan){
		return menuTouchPhase = UITouchPhaseMoved;
	}else if(menuTouchPhase == UITouchPhaseEnded)
	{
		return menuTouchPhase = UITouchPhasePending;
	}
		return 	menuTouchPhase ;
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