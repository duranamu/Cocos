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
#include "UIView.h"
void 
	UIView::viewDidRender(CCLayer* host)
{
	host->addChild(sprite);
}
void 
	UIView::followPlayer(CCPoint3D* data)
{
	sprite->setPosition(ccp(data->x,480 - data->y));
}
bool 
	UIView::canTriggerforTouch(UITouch* touch)
{
	if(!sprite->getParent())
	{
	NSInteger touchx = touch->getlocation().x ;
	NSInteger touchy = touch->getlocation().y;
	NSInteger spritex =  sprite->getPosition().x ;
	NSInteger offx = touchx - spritex;
	NSInteger halfSpriteWidth = sprite->getTexture()->getPixelsWide()/2;
	NSInteger halfSpriteHeight = sprite->getTexture()->getPixelsHigh()/2;
	 if(abs(offx) < halfSpriteWidth)
	 {
		NSInteger spritey = sprite->getPosition().y;
		NSInteger offy = touchy - spritey;
		 if(abs(offy) < halfSpriteHeight )
		 {
			 return true;
		 }
	 }
		return false;
	}else{
		return canTriggerforTouch_parentSprite(touch,(CCSprite*)sprite->getParent());
	}
}
bool
	UIView::canTriggerforTouch_parentSprite(UITouch* touch , CCSprite* parent)
{
	NSInteger touchx = touch->getlocation().x  ;
	NSInteger touchy = touch->getlocation().y;
	NSInteger spritex =  sprite->getPosition().x + parent->getPosition().x;
	NSInteger offx = touchx - spritex;
	NSInteger halfSpriteWidth = sprite->getTexture()->getPixelsWide()/2;
	NSInteger halfSpriteHeight = sprite->getTexture()->getPixelsHigh()/2;
	 if(abs(offx) < halfSpriteWidth)
	 {
		NSInteger spritey = sprite->getPosition().y + parent->getPosition().y;
		NSInteger offy = touchy - spritey;
		 if(abs(offy) < halfSpriteHeight )
		 {
			 return true;
		 }
	 }
	return false;
}
void
	UIView::moveByPoint(CCPoint point)
{
	/*CCAction* action = CCMoveBy::actionWithDuration(0.01f,point);
	this->sprite->runAction(action);*/
	CCPoint position = this->sprite->getPosition();
	position.y += point.y;
	this->sprite->setPosition(position);
}
void 
	UIView::addGestureRecognizer(UIGestureRecognizer* gesture)
{
	if(!self->recognizerSheet)
	{
		self->recognizerSheet = NSArray::arrayWithCapacity(2);
		self->recognizerSheet->retain();
	}
	self->recognizerSheet->addObject(gesture);
}
void
	UIView::touchesBegan_withEvent(_set* touches ,UIEvent* events) 
{
	/*if(self->recognizerSheet)
		For(UIGestureRecognizer* ,recognizer , self->recognizerSheet)
			recognizer->touchesBegan_withEvent(touches,events);
		forCCEnd*/
}
void
	UIView::touchesMoved_withEvent(_set* touches ,UIEvent* events) 
{
	/*if(self->recognizerSheet)
	For(UIGestureRecognizer* ,recognizer , self->recognizerSheet)
		recognizer->touchesMoved_withEvent(touches,events);
	forCCEnd	*/
}
void
	UIView::touchesEnded_withEvent(_set* touches ,UIEvent* events)
{
	/*if(self->recognizerSheet)
	For(UIGestureRecognizer* ,recognizer , self->recognizerSheet)
		recognizer->touchesEnded_withEvent(touches,events);
	forCCEnd*/
}
BOOL
	UIView::pointInside_withEvent(CGPoint point,UIEvent* evt)
{
	UITouch* touch = (UITouch*) evt->allTouches()->anyObject();

	return self->canTriggerforTouch(touch);
}
UIView*
	UIView::hitTest_withEvent(CGPoint point ,UIEvent* evt)
{
	UIView* view = self;
	NSArray* match_stack = NSArray::array();

	if(view->subviews->count())
	{
		For(UIView*,dscendant,view->subviews)
			if(dscendant->pointInside_withEvent(point,evt))
			{
				if(dscendant->subviews->count())
				{
					UIView* object = dscendant->hitTest_withEvent(point,evt);
					if(object)
						if(object->canBecomeFirstResponder())
							match_stack->addObject(object);
				}else{
					
						match_stack->addObject(dscendant);
				}
			}
		forEnd
	};
	return (UIView*) match_stack->lastObject();
}
void
	UIView::dealloc(){}
