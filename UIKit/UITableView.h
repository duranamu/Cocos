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
#pragma once
#include <UIKit/UIView.h>
#include <Foundation/Foundation.h>
#include <UIKit/UITableViewDelegate.h>
#include <UIKit/UITableViewCell.h>
NS_CLASS UITableViewDataSource;
NS_CLASS UITableViewCell;
NS_INTERFACE( UITableView , UIView )
public:
	UITableView();
	bool 
		isEqual(UITableView* );
	CCArray* 
		m_indexPath;
	UITableViewCell*
		dequeueReusableCellWithIdentifier(NSString* );
	virtual void 
		reloadData(NSMutableArray* );
	void 
		touchesBegan_withEvent(NSSet*  ,UIEvent* );
	void 
		touchesEnded_withEvent(NSSet*  ,UIEvent* );
	void
		touchesMoved_withEvent(NSSet*  ,UIEvent* );
	BOOL
		pointInside_withEvent(CGPoint point,UIEvent* evt);
	void
		tableViewCell_didSelectRowAtIndexPath(UITableViewCell* aCell ,NSIndexPath* indexPath);
protected:
	CCString* identifier;
	NS_SYNTHESIZE
		(UITableViewDelegate* ,delegate)
	NS_SYNTHESIZE
		(UITableViewDataSource* ,datasource);
NS_END