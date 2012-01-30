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
#include "UIViewController.h"
#include "UITouch.h"
void 
	UIViewController::viewDidRender(CCLayer* host)
{
	For(UIView*,pView,view->membersheet)
		pView->viewDidRender(host);
	forCCEnd
}
void 
	UIViewController::viewReloadData(NSArray* toShow)
{
	For(UIView*,pView,view->membersheet)
		pView->reloadData(toShow);
	forCCEnd
}
CCSprite*  
	UIViewController::renderTargetforHost()
{
	return view->anyView()->getSprite();
}
void 
	UIViewController::predo_controller_torsoData(CCNode* sender,void* data)
{
	ccCast(CCPoint3D*,data);

	m_torsox = cdata->x;
	m_torsoy = 480 - cdata->y;

	For(UIView*,m_view,followView->membersheet)
		m_view->followPlayer(cdata);
	forCCEnd

	controller_torsoData(sender,cdata);

	cdata->autorelease();
}
void 
	UIViewController::predo_controller_righthandData(CCNode* sender,void* data)
{
	if(!isRighthandTracked) 
		isRighthandTracked = true;
	ccCast(CCPoint3D*,data);
	m_handz = cdata->z;
	m_handx = cdata->x;
	m_handy = 480 - cdata->y;

	if(self->righthand_clicked_marker )
		self->righthand_clicked_marker->followPlayer(cdata);

	controller_righthandData(sender,cdata);
	cdata->autorelease();
} 
UITouchPhase 
	UIViewController::touchPhaseforTime_handz(cocos2d::ccTime time, float handz)
{
	float deltahandz ;
	deltahandz = g_lasthandz - handz   ;
	g_lasthandz = handz;
	NSInteger velocity = deltahandz / time;
	velocity = (velocity >> 5);

	float deltahandzVelocity;
	deltahandzVelocity = g_lasthandzVelocity - velocity  ;
	g_lasthandzVelocity = velocity;	
	NSInteger acceleration = deltahandzVelocity /time;
	acceleration = (acceleration >>6);

	if(velocity > 40 & acceleration < 0)
	{		
		if( menuTouchPhase ==  UITouchPhasePending )
		{
			return menuTouchPhase = UITouchPhaseBegan;
		}else{
			return menuTouchPhase;
		}
	}else if (velocity < 0 & acceleration < 5){
		if(menuTouchPhase == UITouchPhaseMoved)
		{
			return menuTouchPhase = UITouchPhaseEnded;
		}else{
			return menuTouchPhase;
		}
	}else{
		if( menuTouchPhase ==  UITouchPhasePending)
		{
			return UITouchPhasePending;
		}else if (menuTouchPhase ==  UITouchPhaseBegan){
			return menuTouchPhase =  UITouchPhaseMoved;
		}else if (menuTouchPhase ==  UITouchPhaseMoved){
			return menuTouchPhase ;
		}else{
			return menuTouchPhase =  UITouchPhasePending;
		}
	}
}
void
	UIViewController::controllerDidUpdate(cocos2d::ccTime time)
{
	if(isRighthandTracked)
	{
		UITouchPhase ability; ;
		ability = touchPhaseforTime_handz(time,m_handz);
		if(ability == UITouchPhaseBegan | ability == UITouchPhaseEnded )
		{
			 UITouch* touch = UITouch::touchWithPhase(ability);
			 touch->settimestamp(time);
			 touch->setlocation ( ccp( m_handx , m_handy ));
			 UITouch* lefthand_touch = UITouch::touchWithPhase(ability);
			 lefthand_touch->settimestamp(time);
			 lefthand_touch->setlocation ( ccp( ml_handx , ml_handy ));
			 CCSet* set = new CCSet();
			 set->addObject(lefthand_touch);
			 set->addObject(touch);
			 UIEvent* events = new UIEvent( set );
			 if( ability == UITouchPhaseBegan)
			 {
				 touchStartx = m_handx;
				 touchStarty = m_handy;
				 touchStartTime = time;
				 this->touchesBegin_withEvent(set,events);
			 }else if (ability == UITouchPhaseEnded)
				 this->touchesEnded_withEvent(set,events);
			 events->release();
			 set->release();
		}else if (ability == UITouchPhaseMoved )
	    {
			 UITouch* touch = UITouch::touchWithPhase(ability);
			 touch->settimestamp(time);
			 touch->setlocation (ccp(m_handx , m_handy ));
			 CCSet* set = new CCSet();
			 set->addObject(touch);
			 UIEvent* events = new UIEvent(set);
			 this->touchesMoved_withEvent( set , events );
			 events->release();
			 set->release();
		}
	}
}
void 
	UIViewController::touchesBegin_withEvent(CCSet* touches ,UIEvent* events)
{
	self->view->touchesBegin_withEvent(touches,events);

	For(UIView*,uiview,this->view->membersheet)
		uiview->touchesBegin_withEvent(touches,events);
	forCCEnd
}
void 
	UIViewController::touchesEnded_withEvent(CCSet* touches ,UIEvent* events)
{
	newTouchSession = true;
	self->view->touchesEnded_withEvent(touches,events);
	For(UIView*,uiview,this->view->membersheet)
		uiview->touchesEnded_withEvent(touches,events);
	forCCEnd
}
void 
	UIViewController::touchesMoved_withEvent(CCSet* touches ,UIEvent* events )
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

	For(UIView*,uiview,this->movableView->membersheet)
		uiview->touchesMoved_withEvent(touches,events);
	forCCEnd
}
void
	UIViewController::predo_controller_lefthandData(CCNode* sender , vid data)
{
	ccCast(CCPoint3D*,data);
	ml_handz = cdata->z;
	ml_handx = cdata->x;
	ml_handy = 480 - cdata->y;
}