/****************************************************************************
	UIKit OpenSource Project
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
#include "UITapGestureRecognizer.h"
#include "UITouch.h"
NS_STATIC_ALLOC( UITapGestureRecognizer );
UITapGestureRecognizer*
	UITapGestureRecognizer::initWithTarget_action(NSActionTarget* ctarget ,SEL_CallFuncND cselector)
{
	self->m_pListener = ctarget;
	self->m_pSelector = cselector;
	return self;
}
	UITapGestureRecognizer::UITapGestureRecognizer()
{
	self->numberOfTapsRequired = 1;
	self->numberOfTapsAcquired = 0;
	self->tapStartTime = 0;
	self->m_pListener = nil;
	self->m_pSelector = nil;
}
void
	UITapGestureRecognizer::touchesBegan_withEvent(_set* touches ,UIEvent* events)
{
	CGFloat newStartTime = ((UITouch*) touches->anyObject())->gettimestamp();
	if( newStartTime - self->tapStartTime  > 0.005f)
	{
		self->numberOfTapsAcquired = 0;
	}
	self->tapStartTime = newStartTime;
}
void
	UITapGestureRecognizer::touchesMoved_withEvent(_set* touches ,UIEvent* events)
{

}
void
	UITapGestureRecognizer::touchesEnded_withEvent(_set* touches ,UIEvent* events)
{
	CGFloat endTime = ((UITouch*) touches->anyObject())->gettimestamp();
	CGFloat timediff = endTime -  self->tapStartTime ;
	if( timediff < 0.1f && timediff > 0.002f)
	{
		self->numberOfTapsAcquired++;

		if(self->numberOfTapsAcquired == self->numberOfTapsRequired)
		{
			self->numberOfTapsAcquired = 0;
			(self->m_pListener->*m_pSelector)(nil,self);
		}

	}
}