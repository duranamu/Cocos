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
#include <UIKit/UIViewController.h>
#include <UIKit/UITouch.h>
#define super UIView
void 
	UIViewController::viewDidRender(CCLayer* host)
{
	nfor(UIView*,pView,view->getsubviews())
		pView->viewDidRender(host);
	nend
}
void 
	UIViewController::viewReloadData(NSMutableArray* toShow )
{
	nfor(UIView*,pView,view->getsubviews())
		pView->reloadData(toShow);
	nend
}
CCNode*  
	UIViewController::renderTargetforHost()
{
	return view->anyView()->getnode();
}
void 
	UIViewController::touchesBegan_withEvent(NSSet* touches ,UIEvent* events)
{
	self->view->touchesBegan_withEvent(touches,events);
	UITouch* touch = (UITouch*)touches->anyObject();
	receiver = self->view->hitTest_withEvent(touch->getlocation(),events);
	if(receiver)
	{
		if(receiver->gestureRecognizers)
		{
			nfor(UIGestureRecognizer* , gr ,receiver->gestureRecognizers)
				gr->touchesBegan_withEvent(touches , events);
			nend
		}
		receiver->touchesBegan_withEvent(touches,events);
	}
}
void 
	UIViewController::touchesEnded_withEvent(NSSet* touches ,UIEvent* events)
{
	newTouchSession = true;
	t_lasthandx = 0;
	t_lasthandy = 0;
	self->view->touchesEnded_withEvent(touches,events);

	if(receiver)
	{
		if(receiver->gestureRecognizers)
		{
			nfor(UIGestureRecognizer* , gr ,receiver->gestureRecognizers)
				gr->touchesEnded_withEvent(touches , events);
			nend
		}
		receiver->touchesEnded_withEvent(touches,events);
	}
}
void 
	UIViewController::sender_torsoData(void* sender,vid data)
{
	NSCAST(CIVector*,data);
	nfor(UIView* , m_view , followView->getsubviews())
		m_view->followPlayer(cdata);
	nend
	cdata->autorelease();
}
void 
	UIViewController::touchesMoved_withEvent(NSSet* touches ,UIEvent* events)
{
	self->view->touchesMoved_withEvent(touches,events);

	if(receiver)
	{
		if(receiver->gestureRecognizers)
		{
			nfor(UIGestureRecognizer* , gr ,receiver->gestureRecognizers)
				gr->touchesMoved_withEvent(touches , events);
			nend
		}
	}
}
void
	UIViewController::retain()
{
}
void
	UIViewController::release()
{
}
void
	UIViewController::dealloc()
{
	self->followView->release();
	self->followView = nil;
	self->view->release();
	self->view = nil;
	self->clickView->release();
	self->clickView = nil;
}
void
	UIViewController::loadView()
{
	if(self->storyboard == nil)
	{
		self->view = UIView::alloc()->init();
	}else{
		//todo load UIViewController from associated storyboard
	}
}
UIViewController*
	UIViewController::init()
	{
		if(super::init())
		{
		self->view		   = UIView::alloc()->init();
		self->followView   = UIView::alloc()->init();
		self->clickView    = UIView::alloc()->init();
		self->receiver     = nil;
		}
		return self;
	}