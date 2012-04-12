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
#include <UIKit/UIViewController.h>
#include <UIKit/UITableViewDataSource.h>
#include <UIKit/UITableViewDelegate.h>
NS_PROTOCOL_CONFORM(UITableViewController ,public  UIViewController , public UITableViewDataSource ,public NSObjectProtocol ,public UITableViewDelegate)
	virtual void 
		viewDidLoad(void ) 
	{
		printf("sdf");
	}
	virtual void 
		viewDidUnload(void) = 0;
	virtual UITableViewCell* 
		tableView_cellForRowAtIndexPath(UIView* tableView,NSIndexPath* indexPath) = 0;
	virtual NSInteger
		numberOfSectionInTableView(UIView* tableView) = 0;
	virtual NSInteger
		tableView_numberOfRowsInSection(UIView* view , NSInteger section) = 0;
	virtual void
		tableView_didSelectRowAtIndexPath(UITableView* tableView ,NSIndexPath* indexPath) = 0;
	virtual void 
		viewDidUpdate(cocos2d::CGFloat time) {};
protected:
	NS_SYNTHESIZE_RETAIN
	  (UITableView* ,tableView);
	NS_SYNTHESIZE
	  (BOOL ,clearsSelectionOnViewWillAppear);
NS_END