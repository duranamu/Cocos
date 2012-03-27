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
#include <UIKit/UIWindow.h>
NS_CLASS UIEvent;
class UIApplication :public UIView , public NSObjectProtocol
{
public:
	vid 
		predo_controller_torsoData(void*,vid);
	vid 
		predo_controller_righthandData(void* ,vid);
	vid
		predo_controller_lefthandData(void*, vid);
	vid
		sender_neckData(vid,vid);
	vid
		sender_rightElbowData(vid,vid);
	vid
		sender_rightFingertipData(vid,vid);
	UITouchPhase 
		touchPhaseforTime_handz(CGFloat,CGFloat);
	void 
		addWindow(UIWindow*);
	void
		selectKeyWindow();

	static UIApplication*
		sharedApplication();
	
	NS_ALLOC_FULL(UIApplication) 
	NS_INIT_FULL(UIApplication) 
	NS_DEALLOCATE(UIApplication)

	UIApplication();
	void
		sentEvent(UIEvent*);
	void
		applicationDidUpdate(CGFloat);
	void
		setupTracker();

protected:
	NITrackerManager* trackerManager;
	NITracker* torsoTracker;
	NITracker* righthandTracker;
	NITracker* lefthandTracker;
	NITracker* neckTracker;
	NS_SYNTHESIZE
		(CGFloat,rightFingertipz);
	NS_SYNTHESIZE
		(CGFloat,rightFingertipx);
	NS_SYNTHESIZE
		(CGFloat,rightFingertipy);
	NS_SYNTHESIZE
		(CGFloat,rightElbowx);
	NS_SYNTHESIZE
		(CGFloat,rightElbowy);
	NS_SYNTHESIZE
		(CGFloat,rightElbowz);
	NS_SYNTHESIZE
		(CGFloat , neckx);
	NS_SYNTHESIZE
		(CGFloat , necky);
	NS_SYNTHESIZE
		(CGFloat , neckz);
	NS_SYNTHESIZE
		(CGFloat ,rightHandShadowz);
	NS_SYNTHESIZE
		(CGFloat ,rightHandShadowzVelocity);
	NS_SYNTHESIZE
		(CGFloat ,rightHandz);
	NS_SYNTHESIZE
		(CGFloat ,rightHandx);
	NS_SYNTHESIZE
		(CGFloat ,rightHandy);
	NS_SYNTHESIZE
		(CGFloat ,leftHandShadowz);
	NS_SYNTHESIZE
		(CGFloat ,leftHandShadowzVelocity);
	NS_SYNTHESIZE
		(CGFloat ,leftHandz);
	NS_SYNTHESIZE
		(CGFloat ,leftHandx);
	NS_SYNTHESIZE
		(CGFloat ,leftHandy);
	NS_SYNTHESIZE
		(CGFloat ,torsox);
	NS_SYNTHESIZE
		(CGFloat ,torsoy);
	NS_SYNTHESIZE
		(BOOL ,isRighthandTracked);
		
	UITouchPhase menuTouchPhase;
	NS_SYNTHESIZE
		(CGFloat ,touchStartx);
	NS_SYNTHESIZE
		(CGFloat ,touchStarty);
	CGFloat touchStartTime;
	NS_SYNTHESIZE
		(CGFloat ,t_lasthandx);
	NS_SYNTHESIZE
		(CGFloat ,t_lasthandy);
	bool newTouchSession;
	NS_SYNTHESIZE
		(UIWindow* , keyWindow);
	NS_SYNTHESIZE
		(NSArray* , windows);
	NS_SYNTHESIZE
		(vid , scene);
};
int UIApplicationMain (
   int argc,
   char *argv[],
   NSString *principalClassName,
   NSString *delegateClassName
);