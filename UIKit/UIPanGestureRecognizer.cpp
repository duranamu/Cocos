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
#include <UIKit/UIPanGestureRecognizer.h>
#include <UIKit/UITouch.h>
#define super UIGestureRecognizer
UIPanGestureRecognizer*
	UIPanGestureRecognizer::initWithTarget_action(NSActionTarget* ctarget ,SEL_PP cselector)
{
	if(super::init())
	{
		self->m_pListener = ctarget;
		self->m_pSelector = cselector;
		self->velocity    = ccp(0,0);
	}
	return self;
}
void
	UIPanGestureRecognizer::touchesBegan_withEvent(NSSet* touches ,UIEvent* events)
{
	self->state = UIGestureRecognizerStatePossible;
	if(dependenceCheck())
	{
		UITouch* touch = (UITouch*) touches->anyObject();
		self->recentTouchLocation =  touch->locationInView();
		self->touchesSource = touch->gettouchSource();
		self->state = UIGestureRecognizeStateBegan;
	}
}
void
	UIPanGestureRecognizer::touchesMoved_withEvent(NSSet* touches ,UIEvent* events)
{
	if(self->state != UIGestureRecognizeStateBegan && self->state != UIGestureRecognizeStateChanged)
	{
		return;
	}
	UITouch* touch = (UITouch*) touches->anyObject();
	
	CGPoint deltaMove = touch->getdeltaMove();
	NSTimeInterval deltaTime = touch->getdeltaTime();
	if(deltaMove.x ==0 && deltaMove.y == 0)
	{
	CGPoint loaction  =  touch->locationInView();
	self->deltaDisplacement.x = loaction.x - self->recentTouchLocation.x;
	self->deltaDisplacement.y = loaction.y - self->recentTouchLocation.y;
	self->recentTouchLocation = loaction;
	}else{
		self->deltaDisplacement.x = deltaMove.x;
		self->deltaDisplacement.y = deltaMove.y;
	}
	self->velocity.x = self->deltaDisplacement.x  / deltaTime;
	self->velocity.y = self->deltaDisplacement.y  /deltaTime;
	if(m_pListener!=nil)
		(m_pListener->*m_pSelector)(m_pListener,(UIPanGestureRecognizer*)self);
}
void
	UIPanGestureRecognizer::touchesEnded_withEvent(NSSet* touches ,UIEvent* events)
{
	if(self->state == UIGestureRecognizeStateChanged)
	{
		self->state = UIGestureRecognizeStateEnded;
	}
}
CGPoint
	UIPanGestureRecognizer::translationInView(UIView* view)
{
	return self->touchStartLocation;
}
CGPoint
	UIPanGestureRecognizer::velocityInView(UIView* view)
{
	return self->velocity;
}
void
	UIPanGestureRecognizer::dealloc(){}