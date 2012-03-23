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
	host->addChild(self->node);
}
void 
	UIView::followPlayer(CIVector* data)
{
	self->node->setPosition(ccp(data->getX(),480 - data->getY()));
}
bool 
	UIView::canTriggerforTouch(UITouch* touch)
{
	if(!node->getParent())
	{
	NSInteger touchx = touch->getlocation().x ;
	NSInteger touchy = touch->getlocation().y;
	NSInteger spritex =  node->getPosition().x ;
	NSInteger offx = touchx - spritex;
	CCSprite* sprite = (CCSprite*) node;
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

		return canTriggerforTouch_parentSprite(touch,(CCSprite*)node->getParent());
	}
}
bool
	UIView::canTriggerforTouch_parentSprite(UITouch* touch , CCSprite* parent)
{
	CCSprite* sprite = (CCSprite*) self->node;
	NSInteger touchx = touch->getlocation().x  ;
	NSInteger touchy = touch->getlocation().y;
	NSInteger spritex =  node->getPosition().x + parent->getPosition().x;
	NSInteger offx = touchx - spritex;
	NSInteger halfSpriteWidth = sprite->getTexture()->getPixelsWide()/2;
	NSInteger halfSpriteHeight = sprite->getTexture()->getPixelsHigh()/2;
	 if(abs(offx) < halfSpriteWidth)
	 {
		NSInteger spritey = node->getPosition().y + parent->getPosition().y;
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
	CCPoint position = this->node->getPosition();
	position.y += point.y;
	this->node->setPosition(position);
}
void 
	UIView::addGestureRecognizer(UIGestureRecognizer* gesture)
{
	if(!self->gestureRecognizers)
	{
		self->gestureRecognizers = NSArray::arrayWithCapacity(2);
		self->gestureRecognizers->retain();
	}
	self->gestureRecognizers->addObject(gesture);
}
void
	UIView::touchesBegan_withEvent(CCSet* touches ,UIEvent* events) 
{
	/*if(self->gestureRecognizers)
		nfor(UIGestureRecognizer* ,recognizer , self->gestureRecognizers)
			recognizer->touchesBegan_withEvent(touches,events);
		nend*/
}
void
	UIView::touchesMoved_withEvent(CCSet* touches ,UIEvent* events) 
{
	/*if(self->gestureRecognizers)
	nfor(UIGestureRecognizer* ,recognizer , self->gestureRecognizers)
		recognizer->touchesMoved_withEvent(touches,events);
	nend	*/
}
void
	UIView::touchesEnded_withEvent(CCSet* touches ,UIEvent* events)
{
	/*if(self->gestureRecognizers)
	nfor(UIGestureRecognizer* ,recognizer , self->gestureRecognizers)
		recognizer->touchesEnded_withEvent(touches,events);
	nend*/
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
	NSArray* match_stack = NSArray::alloc()->init();

	if(view->subviews->count())
	{
		nfor(UIView*,dscendant,view->subviews)
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
	UIView::dealloc()
{
	self->subviews->release();
	self->subviews = nil;
	self->node->release();
	self->node = nil;
	self->indexPath->release();
	self->indexPath = nil;
}