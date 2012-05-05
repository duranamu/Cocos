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
#include <UIKit/UITableViewCell.h>
#include <UIKit/UITouch.h>
#include <UIKit/UIImageView.h>
#include <UIKit/UITableView.h>
#include <UIKit/UIPanGestureRecognizer.h>
#define super UIView
 UITableViewCell* 
		UITableViewCell::initWithStyle_reuseIdentifier(UITableViewStyle oneStyle ,NSString* id)
	{
		self->style = oneStyle;
		id->retain();
		uid = id;
		return self;
	}
  UITableViewCell* 
		UITableViewCell::initWithStyle_reuseIdentifier_target_selector(UITableViewStyle oneStyle ,NSString* id,NSActionTarget* target,SEL_PP cselector)
	{
		style = oneStyle;
		id->retain();
		uid =  id;
		listener = target;
		selector = cselector;
		return self;
	}
UITableViewCell*	
	 UITableViewCell::init()
	{
		if(super::init())
		{
		if(style == UITableViewSylePlain)
			textLabel = CCLabelTTF::labelWithString("","Arial",38);
		else
			textLabel = CCLabelTTF::labelWithString("","Arial",38);
		setnode(textLabel);
		self->imageView =  UIImageView::alloc()->init();
		self->contentView =  UIView::alloc()->init();
		self->retain();
		self->accessoryType = UITableViewCellAccessoryDefault;
		self->indentationLevel = 0;
		self->indentationWidth = 10;
		self->indexPath = NSIndexPath::alloc()->init();
		}
		return self;
	}
void 
	UITableViewCell::touchesBegan_withEvent(NSSet* touches ,UIEvent* events)
{
	UITouch* touch = (UITouch*)touches->anyObject();

	bool isCildTrigger = false;
	nfor(UIView* , child , self->subviews )
		if(child->canTriggerforTouch(touch))
			isCildTrigger = true;
	nend
		if(imageView->canTriggerforTouch(touch))
			isCildTrigger = true;

	if(this->canTriggerforTouch(touch) | isCildTrigger)
	{
		(listener->*selector)(listener , this);
	}
	UITableView* tableView = (UITableView*) self->getsuperview();
	tableView->tableViewCell_didSelectRowAtIndexPath(self,self->indexPath);
}
void 
	UITableViewCell::touchesEnded_withEvent(NSSet* touches ,UIEvent* events)
{
}
void 
	UITableViewCell::touchesMoved_withEvent(NSSet* touches ,UIEvent* events)
{
}
vid
	UITableViewCell::deltaDisplace(vid sender ,vid gestureRecognizer)
{
	NSCAST(UIPanGestureRecognizer* , gestureRecognizer);
	NSCAST(UITableViewCell*,sender);
	
	return nil;
}
void 
	UITableViewCell::setaccessoryType(UITableViewCellAccessory var)
{
	switch(var)
	{
		case UITableViewCellAccessoryDisclosureIndicator:
		{
			self->accessory = CCSprite::spriteWithFile("disclosure_indicator.png");
			self->node->addChild(self->accessory);
			self->accessory->setPosition(ccp(240,20));
			break;
		}
		case UITableViewCellAccessoryDetailDisclosureButton:
		{
			self->accessory = CCSprite::spriteWithFile("detail_disclosure_button.png");
			self->node->addChild(self->accessory);
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
void
	UITableViewCell::dealloc()
{
	self->uid->release();
	self->uid = nil;
	self->imageView->release();
	self->imageView = nil;
}

