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
#include <UIKit/UIDualPushGestureRecognizer.h>
#include <UIKit/UISwipeGestureRecognizer.h>
#define super UIGestureRecognizer
void
	UIDualPushGestureRecognizer::dealloc()
{
}
UIDualPushGestureRecognizer*
	UIDualPushGestureRecognizer::initWithTarget_action(NSActionTarget* actionTarget ,SEL_PP selector)
{
	if( super::init())
	{
		self->m_pListener = actionTarget;
		self->m_pSelector = selector;
		self->didLeftSwipePass = NO;
		self->didRightSwipePass =NO;
	}
	return self;
}
void
	UIDualPushGestureRecognizer::wakeupTargetWithSelector(UIDualPushGestureRecognizer* sender)
{
	if(sender->getdidLeftSwipePass() && sender->getdidRightSwipePass())
	{
		self->state = UIGestureRecognizerStateRecognized;
		(sender->m_pListener->*sender->m_pSelector)(nil ,sender);
		setdidLeftSwipePass(NO);
		setdidRightSwipePass(NO);
	}
		self->state = UIGestureRecognizerStateFailed;
}
void
	UIDualPushGestureRecognizer::touchesBegan_withEvent(NSSet* touches ,UIEvent* events)
{
	if(super::dependenceCheck() && touches->count() > 1)
	{
		nfor(UITouch* ,touch ,touches)
			if(touch->gettouchSource() & UITouchSourceLeftHand)
			{
				self->leftTouchLocation = touch->getlocation();
			}else if(touch->gettouchSource() & UITouchSourceRightHand)
			{
				self->rightTouchLocation = touch->getlocation();
			}
		nend
		self->state = UIGestureRecognizerStatePossible;
	}else{
		self->state = UIGestureRecognizerStateFailed;
	}
}
void
	UIDualPushGestureRecognizer::touchesMoved_withEvent(NSSet* touches ,UIEvent* events)
{
	/*if(self->state ==UIGestureRecognizerStatePossible)
	{
		self->leftSwipe->touchesMoved_withEvent(touches,events);
		self->rightSwipe->touchesMoved_withEvent(touches,events);
		self->state = UIGestureRecognizeStateChanged;
	}*/
}
void
	UIDualPushGestureRecognizer::touchesEnded_withEvent(NSSet* touches ,UIEvent* events)
{
	if(self->state == UIGestureRecognizerStatePossible  && touches->count() > 1)
	{
		nfor(UITouch* ,touch ,touches)
			if(touch->gettouchSource() & UITouchSourceLeftHand && touch->getphase() == UITouchPhaseEnded)
			{
				UISwipeGestureRecognizerDirection leftTouchDirection = UISwipeGestureRecognizer::directionFrom_to(self->leftTouchLocation ,
					touch->getlocation(),6);
				if(leftTouchDirection & UISwipeGestureRecognizerDirectionLeft)
				{
					self->didLeftSwipePass = YES;
				}
			}else if(touch->gettouchSource() & UITouchSourceRightHand && touch->getphase() == UITouchPhaseEnded)
			{
				UISwipeGestureRecognizerDirection rightTouchDirection = UISwipeGestureRecognizer::directionFrom_to(self->rightTouchLocation ,
					touch->getlocation(),6);
				if(rightTouchDirection & UISwipeGestureRecognizerDirectionRight)
				{
					self->didRightSwipePass = YES;
				}
			}
		nend
		wakeupTargetWithSelector(self);
	}
}