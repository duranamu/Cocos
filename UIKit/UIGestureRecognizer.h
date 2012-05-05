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
#include <QuartzCore/QuartzCore.h>
#include <UIKit/UIResponder.h>
#include <UIKit/UITouch.h>
#include <UIKit/UIGestureRecognizerDelegate.h>
typedef enum UIGestureRecognizeState
{
	UIGestureRecognizeStateBegan = 0 ,
	UIGestureRecognizeStateChanged   ,
	UIGestureRecognizeStateEnded     ,
	UIGestureRecognizerStatePossible ,
	UIGestureRecognizerStateCancelled,
 
    UIGestureRecognizerStateFailed,
 
    UIGestureRecognizerStateRecognized = UIGestureRecognizeStateEnded
};
NS_INTERFACE_INIT_SPEC( UIGestureRecognizer , UIResponder )
    virtual void
		touchesBegan_withEvent(NSSet* touches ,UIEvent* events){};
	 virtual void 
		 touchesMoved_withEvent(NSSet* touches ,UIEvent* events){};
	 virtual void 
		 touchesEnded_withEvent(NSSet* touches ,UIEvent* events){};
	 virtual void
		 requireGestureRecognizerToFail(UIGestureRecognizer * otherGestureRecognizer);
	 virtual BOOL
		 canPreventGestureRecognizer(UIGestureRecognizer * preventingGestureRecognizer ){ return NO;};
	 virtual BOOL
		 canBePreventedGestureRecognizer(UIGestureRecognizer * preventedGestureRecognizer) { return NO;};
	 virtual BOOL
		 dependenceCheck();
	 UIGestureRecognizer* init();
protected:
	NS_SYNTHESIZE
		(UIGestureRecognizeState , state);
	NSMutableArray* recognizersRequiredFailed;
	NSActionTarget* m_pListener;
	SEL_PP  m_pSelector;
	NS_SYNTHESIZE
		(UITouchSource ,touchesSource );
	NS_SYNTHESIZE
		(UIGestureRecognizerDelegate* ,delegate);
NS_END