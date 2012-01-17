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
	UIView::triggerableforTouch(UITouch* touch)
{
	if(!sprite->getParent())
	{
	 int touchx = touch->locationInView.x ;
	 int touchy = touch->locationInView.y;
	 int spritex =  sprite->getPosition().x ;
	 int offx = touchx - spritex;
	 int halfSpriteWidth = sprite->getTexture()->getPixelsWide()/2;
	 int halfSpriteHeight = sprite->getTexture()->getPixelsHigh()/2;
	 if(abs(offx) < halfSpriteWidth)
	 {
		 int spritey = sprite->getPosition().y;
		 int offy = touchy - spritey;
		 if(abs(offy) < halfSpriteHeight )
		 {
			 return true;
		 }
	 }
		return false;
	}else{
		return triggerableforTouch_parentSprite(touch,(CCSprite*)sprite->getParent());
	}
}
bool
	UIView::triggerableforTouch_parentSprite(UITouch* touch , CCSprite* parent)
{
	int touchx = touch->locationInView.x  ;
	 int touchy = touch->locationInView.y;
	 int spritex =  sprite->getPosition().x + parent->getPosition().x;
	 int offx = touchx - spritex;
	 int halfSpriteWidth = sprite->getTexture()->getPixelsWide()/2;
	 int halfSpriteHeight = sprite->getTexture()->getPixelsHigh()/2;
	 if(abs(offx) < halfSpriteWidth)
	 {
		 int spritey = sprite->getPosition().y + parent->getPosition().y;
		 int offy = touchy - spritey;
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