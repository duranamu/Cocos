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
	forCCArray(view->membersheet)
		eachCCObject(UIView*,pView);
		pView->viewDidRender(host);
	forCCEnd
}
void 
	UIViewController::viewReloadData(CCArray* toShow)
{
	forCCArray(view->membersheet)
		eachCCObject(UIView*,pView);
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

	forCCArray(followView->membersheet)
		eachCCObject(UIView*,m_view)
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

	controller_righthandData(sender,cdata);

	cdata->autorelease();
} 
UITouchPhase 
	UIViewController::touchPhaseforTime_handz(cocos2d::ccTime time, float handz)
{
	float deltahandz ;
	deltahandz = g_lasthandz - handz   ;
	g_lasthandz = handz;
	int velocity = deltahandz / time;
	velocity = (velocity >> 5);

	float deltahandzVelocity;
	deltahandzVelocity = g_lasthandzVelocity - velocity  ;
	g_lasthandzVelocity = velocity;	
	int acceleration = deltahandzVelocity /time;
	acceleration = (acceleration >>6);

	if(velocity > 30 & acceleration < 2)
	{		
		if( menuTouchPhase ==  UITouchPhasePending)
		{
			return menuTouchPhase = UITouchPhaseBegin;
		}else{
			return menuTouchPhase;
		}
	}else if (velocity < -5 & acceleration < 3){
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
		}else if (menuTouchPhase ==  UITouchPhaseBegin){
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
		if(ability = touchPhaseforTime_handz(time,m_handz))
			touchforHandpoint_view(m_handx  ,  m_handy  , view , ability);
	}
}
void
	UIViewController::touchforHandpoint_view(int hpx, int hpy , UIView* uiview ,UITouchPhase phase)
{
	CCArray* toShow = uiview->membersheet;
	forCCArray(toShow)
		eachCCObject(UIView*,view);
	 CCSprite* sp = view->getSprite();
	 int spx =  sp->getPosition().x;
	 int offx = hpx - spx;
	 int halfSpriteWidth = sp->getTexture()->getPixelsWide()/2;
	 int halfSpriteHeight = sp->getTexture()->getPixelsHigh()/2;
	 if(abs(offx) < halfSpriteWidth)
	 {
		 int spy = sp->getPosition().y;
		 int offy = hpy - spy;
		 if(abs(offy) < halfSpriteHeight )
		 {
			 UITouch* occurredTouch;
			 occurredTouch = UITouch::touchWithPhase(phase);
			 occurredTouch->locationInView = ccp(hpx,hpy);
			 CCSet* set = new CCSet();
			 set->addObject(occurredTouch);
			 UIEvent* events = new UIEvent(set);
			 if(phase == UITouchPhaseBegin)
				 this->touchesBegin_withEvent(set,events);
			 else if (phase == UITouchPhaseEnded )
				 this->touchesEnded_withEvent(set,events);
			 else if (phase == UITouchPhaseMoved )
				 this->touchesMoved_withEvent(set,events);
			 return ;
		 }
	 }
	// sp->setScale(1.0f);
	forCCEnd
}
void 
	UIViewController::touchesBegin_withEvent(CCSet* touches ,UIEvent* events)
{
	forCCArray(this->view->membersheet)
		eachCCObject(UIView*,uiview);
		uiview->touchesBegin_withEvent(touches,events);
	forCCEnd
}
void 
	UIViewController::touchesEnded_withEvent(CCSet* touches ,UIEvent* events)
{
	forCCArray(this->view->membersheet)
		eachCCObject(UIView*,uiview);
		uiview->touchesEnded_withEvent(touches,events);
	forCCEnd
}
void 
	UIViewController::touchesMoved_withEvent(CCSet* touches ,UIEvent* events)
{
	forCCArray(this->movableView->membersheet)
		eachCCObject(UIView*,uiview);
		uiview->touchesMoved_withEvent(touches,events);
	forCCEnd
}