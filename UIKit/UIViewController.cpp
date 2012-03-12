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
void 
	UIViewController::viewDidRender(CCLayer* host)
{
	nfor(UIView*,pView,view->subviews)
		pView->viewDidRender(host);
	nend
}
void 
	UIViewController::viewReloadData(NSArray* toShow)
{
	nfor(UIView*,pView,view->subviews)
		pView->reloadData(toShow);
	nend
}
CCNode*  
	UIViewController::renderTargetforHost()
{
	return view->anyView()->getnode();
}
void 
	UIViewController::touchesBegan_withEvent(CCSet* touches ,UIEvent* events)
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
	UIViewController::touchesEnded_withEvent(CCSet* touches ,UIEvent* events)
{
	newTouchSession = true;

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
	UIViewController::predo_controller_torsoData(void* sender,vid data)
{
	_cast(CCPoint3D*,data);

	m_torsox = cdata->x;
	m_torsoy = 480 - cdata->y;

	nfor(UIView* , m_view , followView->subviews)
		m_view->followPlayer(cdata);
	nend

	cdata->autorelease();
}
void 
	UIViewController::touchesMoved_withEvent(CCSet* touches ,UIEvent* events)
{
	self->view->touchesMoved_withEvent(touches,events);

	UITouch* touch = (UITouch*) touches->anyObject();
	if(touchStartx && touchStarty)
	{
	float x = touch->getlocation().x;
	float y =  touch->getlocation().y;
	float moveSinceTouchX = fabsf( x - t_lasthandx );
	float moveSinceTouchY = 1.5*( y - t_lasthandy);
	t_lasthandx = x;
	t_lasthandy = y;
	/*char var[120];
	sprintf(var,"%3.0f %3.0f",moveSinceTouchX,moveSinceTouchY);
	CCLabelTTF* ttf =(CCLabelTTF*)watchVariableView->sprite;
	ttf->setString(var);*/
		if(newTouchSession)
		{
			newTouchSession = false;
		}else{
			touch->deltaMove = ccp (0 , moveSinceTouchY);
		}
	}
	nfor(UIView*,uiview,this->movableView->subviews)
		uiview->touchesMoved_withEvent(touches,events);
	nend

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
//	self->NSObject::release();
}
void
	UIViewController::dealloc()
{
	self->followView->release();
	self->followView = nil;
	self->view->release();
	self->view = nil;
	self->movableView->release();
	self->movableView = nil;
}