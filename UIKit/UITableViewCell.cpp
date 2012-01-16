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
		UITableViewCell::initWithStyle_reuseIdentifier_target_selector(UITableViewStyle style ,CCString* uid,SelectorProtocol* ctarget,SEL_CallFuncND cselector)
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
	}
void 
	UITableViewCell::touchesBegin_withEvent(CCSet* touches ,UIEvent* events)
{
	if(this->triggerableforTouch((UITouch*)touches->anyObject()))
	{
		this->sprite->setScale(1.3f);
		(listener->*selector)( (CCNode*)listener , this);
	}
}
void 
	UITableViewCell::touchesEnded_withEvent(CCSet* touches ,UIEvent* events)
{
	if(this->triggerableforTouch((UITouch*)touches->anyObject()))
	{
		this->sprite->setScale(1.0f);
	}
}
void 
	UITableViewCell::touchesMoved_withEvent(CCSet* touches ,UIEvent* events)
{
	//if(this->triggerableforTouch((UITouch*)touches->anyObject()))
	//{
	//	//this->sprite->setScale(1.0f);
	//}
}
UITableViewCell* 
	UITableViewCell::doInitWithStyle_reuseIdentifier_target_selector(UITableViewStyle cstyle ,CCString* cid,SelectorProtocol* clistener,SEL_CallFuncND cselector )
{
		style = cstyle;
		uid = new CCString(cid->m_sString.c_str());
		listener = clistener;
		selector = cselector;
		return this;
}