/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

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
#include "..\Cocos\Cocos.h"
UITableView::UITableView()
{
	membersheet = CCArray::array();
	m_indexPath = CCArray::array();
}
UITableView::~UITableView()
{
	//membersheet->release();
	//m_indexPath->release();
}
void 
	UITableView::reloadData(CCArray* toShow)
{
	int numberOfSection = datasource->numberOfSectionInTableView(this);

	if(sprite)
		sprite = CCLabelTTF::labelWithString("","Arial",38);

	int offsetsum = 0;
	for(int section=0; section< numberOfSection ;section++)
	{
		int numberOfRow = datasource->tableView_numberOfRowsInSection(this,section);

		for(int row = 0; row < numberOfRow ; row++)
		{
		CCIndexPath* path = new CCIndexPath(section,row);
		UITableViewCell* member =datasource->tableView_cellForRowAtIndexPath(this,path);
		member->retain();
		membersheet->addObject(member);
		CCSprite* cellsprite = member->getSprite();
		cellsprite ->setPosition(ccp(220,-30+offsetsum));
		sprite->addChild(cellsprite);
		offsetsum += 48;
		//toShow->addObject(cellsprite);
		toShow->addObject(member);
		}
	}
	//sprite->setPosition(ccp(200,0));
}
//TODO implememtation
UITableViewCell* 
	UITableView::dequeueReusableCellWithIdentifier(CCString* id)
{
	UITableViewCell* cell = nil;
	
	return cell;
}
bool
	UITableView::isEqual(UITableView* toCompare)
{
	if( this->m_uID == toCompare->m_uID)
	{
		return true;
	}
		return false;
}