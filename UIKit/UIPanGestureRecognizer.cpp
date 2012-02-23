/****************************************************************************
	Cocos OpenSource Project
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
#include "UIPanGestureRecognizer.h"
#include "UITouch.h"
NS_STATIC_ALLOC( UIPanGestureRecognizer );
UIPanGestureRecognizer*
	UIPanGestureRecognizer::initWithTarget_action(NSActionTarget* ctarget ,SEL_CallFuncND cselector)
{
	self->m_pListener = ctarget;
	self->m_pSelector = cselector;
	self->velocity    = ccp(0,0);
	self->lastTouchTime = 0;
	return self;
}
	UIPanGestureRecognizer::UIPanGestureRecognizer()
{
	self->m_pListener = nil;
	self->m_pSelector = nil;
}
void
	UIPanGestureRecognizer::touchesBegan_withEvent(_set* touches ,UIEvent* events)
{
	UITouch* touch = (UITouch*) touches->anyObject();
	self->touchStartLocation = touch->locationInView();
	self->lastTouchTime = touch->gettimestamp();
}
void
	UIPanGestureRecognizer::touchesMoved_withEvent(_set* touches ,UIEvent* events)
{
	UITouch* touch = (UITouch*) touches->anyObject();
	CGPoint loaction  =  touch->locationInView();
	NSTimeInterval deltaTime = touch->gettimestamp() -  self->lastTouchTime;

	self->velocity.x = (loaction.x - self->touchStartLocation.x ) / deltaTime ;
	self->velocity.y = ( loaction.y - self->touchStartLocation.y ) / deltaTime ;
	self->touchStartLocation = loaction;

	(m_pListener->*m_pSelector)(nil,self);
}
void
	UIPanGestureRecognizer::touchesEnded_withEvent(_set* touches ,UIEvent* events)
{
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
