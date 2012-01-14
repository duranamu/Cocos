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
#ifndef UITABLEVIEWDATASOURCE_H
#define UITABLEVIEWDATASOURCE_H
#include "..\Cocos\Cocos.h"
#include "UIView.h"
#include "UITableViewCell.h"
#include "UIIndexPath.h"
class UITableViewDataSource :public CCObject
{
public:
virtual int 
	numberOfSectionInTableView(UIView* tableView) = 0;
virtual UITableViewCell*
	tableView_cellForRowAtIndexPath(UIView* tableView,CCIndexPath* indexPath=nil) = 0;
virtual int
	tableView_numberOfRowsInSection(UIView* view, int section) = 0;
};
#endif