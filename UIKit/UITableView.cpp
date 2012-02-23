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
#include "UITableView.h"
#include "UIIndexPath.h"
#include <Cocos\Cocos.h>
#include "UIGestureRecognizer.h"
#include "UIColor.h"
UITableView::UITableView()
{
	m_indexPath = CCArray::array();
}
UITableView::~UITableView()
{
	//subviews->release();
	//m_indexPath->release();
}
void 
	UITableView::reloadData(NSArray* toShow)
{
	NSInteger numberOfSection = datasource->numberOfSectionInTableView(self);

	if(sprite)
		sprite = CCLabelTTF::labelWithString("","Arial",38);


	NSInteger offsetsum = 0;
	for(int section=0; section< numberOfSection ;section++ )
	{
	NSInteger numberOfRow = datasource->tableView_numberOfRowsInSection(self,section);

		for(int row = 0; row < numberOfRow ; row++)
		{
		UIIndexPath* path = new UIIndexPath(section,row);
		UITableViewCell* member = datasource->tableView_cellForRowAtIndexPath(self,path);
		member->retain();
		subviews->addObject(member);
		CCSprite* cellsprite = member->getSprite();

	//	cellsprite->setColor(UIColor::redColor()->getcolor3b());

		if(member->imageView)
		{
			member->imageView->sprite->setPosition(ccp(-30,0));
			cellsprite->addChild(member->imageView->sprite);
		}
		
		cellsprite ->setPosition(ccp( 260+ member->getindentationLevel()*member->getindentationWidth() ,-60 + offsetsum));
		sprite->addChild(cellsprite);
		offsetsum += 68;
		toShow->addObject(member);
		}
	}
	subviews->retain();
}
UITableViewCell* 
	UITableView::dequeueReusableCellWithIdentifier(CCString* uid)
{
	UITableViewCell* cell = nil;
	return cell;
}
bool
	UITableView::isEqual(UITableView* toCompare)
{
	if( self->m_uID == toCompare->m_uID)
	{
		return true;
	}
		return false;
}
void 
	UITableView::touchesBegan_withEvent(_set* touches ,UIEvent* events)
{
	For(UITableViewCell*,uiview,self->subviews)
		uiview->touchesBegan_withEvent(touches,events);
	forCCEnd

}
void 
	UITableView::touchesEnded_withEvent(_set* touches ,UIEvent* events) 
{
	For(UITableViewCell*,uiview,self->subviews)
		uiview->touchesEnded_withEvent(touches,events);
	forCCEnd
	
};
void 
	UITableView::touchesMoved_withEvent(_set* touches ,UIEvent* events) 
{
	For(UITableViewCell*,uiview,self->subviews)
		uiview->touchesMoved_withEvent(touches,events);
	forCCEnd
};
//todo tableview needs sprite while blanck image itself ,but not yet has any ;
BOOL
	UITableView::pointInside_withEvent(CGPoint point,UIEvent* evt)
{
	return YES;
}