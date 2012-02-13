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
#include "UIPinchGestureRecognizer.h"
#include "UITouch.h"
UIPinchGestureRecognizer*
	UIPinchGestureRecognizer::alloc()
{
	UIPinchGestureRecognizer* mem = new UIPinchGestureRecognizer();

	if(mem)
	{
		mem->autorelease();
	}else{
		NS_SAFE_DELETE(mem);
	}
	return mem;
}
UIPinchGestureRecognizer*
	UIPinchGestureRecognizer::initWithTarget_action(SelectorProtocol* ctarget,SEL_CallFuncND cselector)
{
	self->m_pListener = ctarget;
	self->m_pSelector = cselector;
	self->scale = 1;
	return self;
}
void
	UIPinchGestureRecognizer::touchesBegan_withEvent(NSSet* touches ,UIEvent* events)
{
	self->state = UIGestureRecognizeStateBegan;
	bool fistTouch = true;
	CGPoint touchLoaction;
	forSet(UITouch* ,touch ,touches)
		if(fistTouch)
		{
			touchLoaction = touch->getlocation();
			fistTouch= false;
		}else{
			self->gestureStartDistance = CGDistanceMake(touchLoaction,touch->getlocation());
		}
	forEnd
}
void
	UIPinchGestureRecognizer::touchesMoved_withEvent(NSSet* touches ,UIEvent* events)
{
	self->state = UIGestureRecognizeStateChanged;
	bool fistTouch = true;
	CGPoint touchLoaction;
	forSet(UITouch* ,touch ,touches)
		if(fistTouch)
	 	{
			touchLoaction = touch->getlocation();
			fistTouch= false;
		}else{
			CGFloat distance = CGDistanceMake(touchLoaction,touch->getlocation());
			self->scale = distance / self->gestureStartDistance;
		}
	forEnd
		(m_pListener->*m_pSelector)(nil,self);
}
void
	UIPinchGestureRecognizer::touchesEnded_withEvent(NSSet* touches ,UIEvent* events)
{
	self->state = UIGestureRecognizeStateEnded;
}
