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
#include <Foundation/Foundation.h>
#include <UIKit/UIView.h>
#include <UIKit/UIImageView.h>
#include <UIKit/UIPanGestureRecognizer.h>
typedef enum UITableViewStyle{
	UITableViewSylePlain = 0
	,UITableViewSyleDefault
};
typedef enum UITableViewCellAccessory{
	UITableViewCellAccessoryDefault = 0,
	UITableViewCellAccessoryDisclosureIndicator ,
	UITableViewCellAccessoryDetailDisclosureButton
};
NS_INTERFACE_INIT_SPEC( UITableViewCell ,UIView , NSObjectProtocol)
	 NS_IGNORE UITableViewCell(){};
	 UITableViewCell* 
		initWithStyle_reuseIdentifier(UITableViewStyle style ,NSString* uid);
	 UITableViewCell* 
		initWithStyle_reuseIdentifier_target_selector(UITableViewStyle ,NSString*,NSActionTarget*,SEL_PP);
	void
		touchesBegan_withEvent(NSSet* touches ,UIEvent* events);
	void
		touchesEnded_withEvent(NSSet* touches ,UIEvent* events);
	void
		touchesMoved_withEvent(NSSet* touches ,UIEvent* events);
	vid
		deltaDisplace(vid sender ,vid gestureRecognizer);
	protected:
	UITableViewStyle style ;
	NS_PROPERTY 
		( UITableViewCellAccessory ,accessoryType);
	NS_SYNTHESIZE 
		( NSInteger , indentationLevel );
	NS_SYNTHESIZE
		( NSInteger , indentationWidth );
	NSString* uid;
	CCSprite* accessory ;
	CCLabelTTF* textLabel;
	NS_SYNTHESIZE_READONLY_RETAIN
		(UIImageView* ,imageView);
	NS_SYNTHESIZE_RETAIN
		(NSIndexPath* ,indexPath);
	UIPanGestureRecognizer* panGestureRecognizer;
NS_END