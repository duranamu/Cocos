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
#include"UITableViewCell.h"
#include "UITouch.h"
 UITableViewCell* 
		UITableViewCell::initWithStyle_reuseIdentifier(UITableViewStyle style ,CCString* uid)
	{
		UITableViewCell* probe = new UITableViewCell();
		if(probe && probe->doInitWithStyle_reuseIdentifier(style,uid))
		{
			probe->autorelease();
			return probe;
		}
		CC_SAFE_DELETE(probe);
		return NULL;
	}
  UITableViewCell* 
		UITableViewCell::initWithStyle_reuseIdentifier_target_selector(UITableViewStyle style ,CCString* uid,NSActionTarget* ctarget,SEL_CallFuncND cselector)
	{
		UITableViewCell* probe = new UITableViewCell();
		if(probe && probe->doInitWithStyle_reuseIdentifier_target_selector(style,uid,ctarget,cselector))
		{
			probe->autorelease();
			return probe;
		}
		CC_SAFE_DELETE(probe);
		return NULL;
	}
 UITableViewCell* 
		UITableViewCell::doInitWithStyle_reuseIdentifier(UITableViewStyle cstyle ,CCString* cid)
	{
		style = cstyle;
		uid = new CCString(cid->m_sString.c_str());
		return this;
	}
	UITableViewCell::UITableViewCell()
	{
		if(style == UITableViewSylePlain)
			textLabel = CCLabelTTF::labelWithString("","Arial",38);
		else
			textLabel = CCLabelTTF::labelWithString("","Arial",38);
		setSprite(textLabel);
		self->imageView = new UIImageView();
		self->contentView = new UIView();
		self->retain();
		self->accessoryType = UITableViewCellAccessoryDefault;
		self->indentationLevel = 0;
		self->indentationWidth = 10;
	}
void 
	UITableViewCell::touchesBegan_withEvent(_set* touches ,UIEvent* events)
{
	UITouch* touch = (UITouch*)touches->anyObject();

	bool isCildTrigger = false;
	For(UIView* , child , self->subviews )
		if(child->canTriggerforTouch(touch))
			isCildTrigger = true;
	forEnd
		if(imageView->canTriggerforTouch(touch))
			isCildTrigger = true;

	if(this->canTriggerforTouch(touch) | isCildTrigger)
	{
		(listener->*selector)( (CCNode*)listener , this);
	}
}
void 
	UITableViewCell::touchesEnded_withEvent(_set* touches ,UIEvent* events)
{
	if(this->canTriggerforTouch((UITouch*)touches->anyObject()))
	{
		this->sprite->setScale(1.0f);
	}
}
void 
	UITableViewCell::touchesMoved_withEvent(_set* touches ,UIEvent* events)
{
	UITouch* touch = (UITouch*) touches->anyObject();
	this->moveByPoint(touch->deltaMove);
}
UITableViewCell* 
	UITableViewCell::doInitWithStyle_reuseIdentifier_target_selector(UITableViewStyle cstyle ,CCString* cid,NSActionTarget* clistener,SEL_CallFuncND cselector )
{
		style = cstyle;
		uid = new CCString(cid->m_sString.c_str());
		listener = clistener;
		selector = cselector;
		return this;
}
void 
	UITableViewCell::setaccessoryType(UITableViewCellAccessory var)
{
	switch(var)
	{
		case UITableViewCellAccessoryDisclosureIndicator:
		{
			self->accessory = CCSprite::spriteWithFile("disclosure_indicator.png");
			self->sprite->addChild(self->accessory);
			self->accessory->setPosition(ccp(240,20));
			break;
		}
		case UITableViewCellAccessoryDetailDisclosureButton:
		{
			self->accessory = CCSprite::spriteWithFile("detail_disclosure_button.png");
			self->sprite->addChild(self->accessory);
			self->accessory->setPosition(ccp(240,20));
			break;
		}
		default:
		{
			break;
		}
	}

}
UITableViewCellAccessory
	UITableViewCell::getaccessoryType()
{
	return self->accessoryType;
}

