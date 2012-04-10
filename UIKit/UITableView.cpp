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
#include <UIKit/UITableView.h>
#include <UIKit/UIGestureRecognizer.h>
#include <UIKit/UIColor.h>
#include <UIKit/UITableViewCell.h>
#include <UIKit/UITableViewDataSource.h>
#include <UIKit/UIImageView.h>
UITableView::UITableView()
{
	m_indexPath = CCArray::array();
}
void 
	UITableView::reloadData(NSMutableArray* toShow)
{
	NSInteger numberOfSection = datasource->numberOfSectionInTableView(self);

	if(self->node)
		self->node = CCLabelTTF::labelWithString("","Arial",38);
	NSInteger offsetsum = 0;
	for(int section=0; section< numberOfSection ;section++ )
	{
		NSInteger numberOfRow = datasource->tableView_numberOfRowsInSection(self,section);
		for(int row = 0; row < numberOfRow ; row++)
		{
		NSIndexPath* path =  NSIndexPath::alloc()->initWithSection_row(section,row);
		UITableViewCell* member = datasource->tableView_cellForRowAtIndexPath(self,path);
		member->retain();
		member->setindexPath(path);
		subviews->addObject(member);
		member->setsuperview(self);
		CCSprite* cellsprite = (CCSprite*)member->getnode();
		path->release();
	//	cellsprite->setColor(UIColor::redColor()->getcolor3b());
		if(member->getimageView())
		{
			member->getimageView()->getnode()->setPosition(ccp(-30,0));
			cellsprite->addChild(member->getimageView()->getnode());
		}	
		cellsprite ->setPosition(ccp( 460+ member->getindentationLevel()*member->getindentationWidth() ,-60 + offsetsum));
		self->node->addChild(cellsprite);
		offsetsum += 68;
		}
	}
	subviews->retain();
}
UITableViewCell* 
	UITableView::dequeueReusableCellWithIdentifier(NSString* uid)
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
	UITableView::touchesBegan_withEvent(NSSet* touches ,UIEvent* events)
{
	
}
void 
	UITableView::touchesEnded_withEvent(NSSet* touches ,UIEvent* events) 
{
};
void 
	UITableView::touchesMoved_withEvent(NSSet* touches ,UIEvent* events) 
{
	nfor(UIView*,aView ,self->subviews)
		aView->touchesMoved_withEvent(touches,events);
	nend
};
//todo tableview needs sprite while blanck image itself ,but not yet has any ;
BOOL
	UITableView::pointInside_withEvent(CGPoint point,UIEvent* evt)
{
	return YES;
}
void
	UITableView::tableViewCell_didSelectRowAtIndexPath(UITableViewCell* aCell ,NSIndexPath* indexPath)
{
	self->delegate->tableView_didSelectRowAtIndexPath(self,indexPath);
}
void
	UITableView::dealloc()
{

}