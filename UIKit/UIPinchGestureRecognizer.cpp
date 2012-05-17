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
#include <UIKit/UIPinchGestureRecognizer.h>
#include <UIKit/UITouch.h>
#define super UIGestureRecognizer
UIPinchGestureRecognizer*
	UIPinchGestureRecognizer::initWithTarget_action(NSActionTarget* ctarget,SEL_PP cselector)
{
	if(super::init())
	{
		self->m_pListener = ctarget;
		self->m_pSelector = cselector;
		self->scale = 1;
	}
	return self;
}
void
	UIPinchGestureRecognizer::touchesBegan_withEvent(NSSet* touches ,UIEvent* events)
{
		self->state = UIGestureRecognizerStatePossible;
		if(super::dependenceCheck())
		{
			if(touches->count() >= 2 )
			{
			self->state = UIGestureRecognizeStateBegan;
			UITouch* anyTouch = (UITouch*)touches->anyObject();
			self->touchesSource = anyTouch->gettouchSource();
			CGPoint touchLoaction;
			nfor(UITouch* ,touch ,touches )
				if(touch->gettouchSource() == UITouchSourceRightHand )
				{
					touchLoaction = touch->getlocation();
				}else{
					self->gestureStartDistance = CGDistanceMake(touchLoaction,touch->getlocation());
				}
			nend
			}else{
			self->state = UIGestureRecognizerStateFailed;
			}
		}
}
void
	UIPinchGestureRecognizer::touchesMoved_withEvent(NSSet* touches ,UIEvent* events)
{
	if(self->state != UIGestureRecognizeStateBegan && self->state != UIGestureRecognizeStateChanged)
	{
		return;
	}
	self->state = UIGestureRecognizeStateChanged;
	CGPoint touchLoaction;
	nfor(UITouch* ,touch ,touches)
		if(touch->gettouchSource() == UITouchSourceRightHand)
	 	{
			touchLoaction = touch->getlocation();
		}else{
			CGFloat distance = CGDistanceMake(touchLoaction,touch->getlocation());
			self->scale = distance / self->gestureStartDistance;
		}
	nend
}
void
	UIPinchGestureRecognizer::touchesEnded_withEvent(NSSet* touches ,UIEvent* events)
{
	if(self->state == UIGestureRecognizeStateChanged)
	{
		self->state = UIGestureRecognizeStateEnded;
		(m_pListener->*m_pSelector)(nil,self);
	}
}
void
	UIPinchGestureRecognizer::dealloc(){}
