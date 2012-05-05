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
#include <QuartzCore/QuartzCore.h>
NS_CLASS UIImage;
#include <UIKit/UIBarItem.h>
typedef enum {
    UIBarButtonSystemItemDone,
    UIBarButtonSystemItemCancel,
    UIBarButtonSystemItemEdit,
    UIBarButtonSystemItemSave,
    UIBarButtonSystemItemAdd,
    UIBarButtonSystemItemFlexibleSpace,
    UIBarButtonSystemItemFixedSpace,
    UIBarButtonSystemItemCompose,
    UIBarButtonSystemItemReply,
    UIBarButtonSystemItemAction,
    UIBarButtonSystemItemOrganize,
    UIBarButtonSystemItemBookmarks,
    UIBarButtonSystemItemSearch,
    UIBarButtonSystemItemRefresh,
    UIBarButtonSystemItemStop,
    UIBarButtonSystemItemCamera,
    UIBarButtonSystemItemTrash,
    UIBarButtonSystemItemPlay,
    UIBarButtonSystemItemPause,
    UIBarButtonSystemItemRewind,
    UIBarButtonSystemItemFastForward,
    UIBarButtonSystemItemUndo,        
    UIBarButtonSystemItemRedo,        
    UIBarButtonSystemItemPageCurl,    
} UIBarButtonSystemItem;
typedef enum {
    UIBarButtonItemStylePlain,
    UIBarButtonItemStyleBordered,
    UIBarButtonItemStyleDone,
} UIBarButtonItemStyle;
NS_INTERFACE(UIBarButtonItem , UIBarItem)
	UIBarButtonItem*
		initWithTitle_style_target_action(NSString* ,UIBarButtonItemStyle, NSActionTarget* ,SEL_PP );
protected:
	NS_SYNTHESIZE
		(SEL_PP , action);
	NS_SYNTHESIZE
		(NSActionTarget* , target);
	NS_SYNTHESIZE
		(UIBarButtonItemStyle ,style);
	NS_SYNTHESIZE
		(NSString* , title);
NS_END