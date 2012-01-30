/****************************************************************************

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
UITapGestureRecognizer*
	UITapGestureRecognizer::alloc()
{
	UITapGestureRecognizer* mem = new UITapGestureRecognizer();
	if(mem)
	{
	}else{
		NS_SAFE_DELETE(mem);
	}
	return mem;
}
UITapGestureRecognizer*
	UITapGestureRecognizer::initWithTarget_action(SelectorProtocol* ctarget ,SEL_CallFuncND cselector)
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
	UITapGestureRecognizer::touchesBegin_withEvent(CCSet* touches ,UIEvent* events)
{
	float newStartTime = ((UITouch*) touches->anyObject())->gettimestamp();
	if( newStartTime - self->tapStartTime  > 0.005f)
	{
		self->numberOfTapsAcquired = 0;
	}
	self->tapStartTime = newStartTime;
}
void
	UITapGestureRecognizer::touchesMoved_withEvent(CCSet* touches ,UIEvent* events)
{

}
void
	UITapGestureRecognizer::touchesEnded_withEvent(CCSet* touches ,UIEvent* events)
{
	float endTime = ((UITouch*) touches->anyObject())->gettimestamp();
	float timediff = endTime -  self->tapStartTime ;
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