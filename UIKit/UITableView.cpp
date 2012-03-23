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
#include <UIKit/UITableView.h>
#include <Foundation/NSIndexPath.h>
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
	UITableView::reloadData(NSArray* toShow)
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
		subviews->addObject(member);
		CCSprite* cellsprite = (CCSprite*)member->getnode();
		path->release();

	//	cellsprite->setColor(UIColor::redColor()->getcolor3b());

		if(member->imageView)
		{
			member->imageView->getnode()->setPosition(ccp(-30,0));
			cellsprite->addChild(member->imageView->getnode());
		}
		
		cellsprite ->setPosition(ccp( 260+ member->getindentationLevel()*member->getindentationWidth() ,-60 + offsetsum));
		self->node->addChild(cellsprite);
		offsetsum += 68;
		toShow->addObject(member);
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
	UITableView::touchesBegan_withEvent(CCSet* touches ,UIEvent* events)
{
	nfor(UITableViewCell*,uiview,self->subviews)
		uiview->touchesBegan_withEvent(touches,events);
	nend

}
void 
	UITableView::touchesEnded_withEvent(CCSet* touches ,UIEvent* events) 
{
	nfor(UITableViewCell*,uiview,self->subviews)
		uiview->touchesEnded_withEvent(touches,events);
	nend
};
void 
	UITableView::touchesMoved_withEvent(CCSet* touches ,UIEvent* events) 
{
	nfor(UITableViewCell*,uiview,self->subviews)
		uiview->touchesMoved_withEvent(touches,events);
	nend
};
//todo tableview needs sprite while blanck image itself ,but not yet has any ;
BOOL
	UITableView::pointInside_withEvent(CGPoint point,UIEvent* evt)
{
	return YES;
}
void
	UITableView::dealloc()
{

}