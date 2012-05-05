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
#include <NIKit/NIKit.h>
#include <UIKit/UIResponder.h>
NS_CLASS UIEvent;
NS_INTERFACE_INIT_SPEC(UIApplication , UIResponder , public NSObjectProtocol)
public:
	vid 
		sender_torsoData(void*,vid);
	vid 
		sender_righthandData(void* ,vid);
	vid
		sender_lefthandData(void*, vid);
	vid
		sender_neckData(vid,vid);
	vid
		sender_rightElbowData(vid,vid);
	vid
		sender_rightCollarData(vid,vid);
	UITouchPhase 
		touchPhaseforTime_handz(CGFloat time,CGFloat handz);
	void 
		addWindow(UIWindow*);
	void
		selectKeyWindow();

	static UIApplication*
		sharedApplication();

	UIApplication* init();
	NS_IGNORE UIApplication(){};
	void
		sentEvent(UIEvent*);
	void
		applicationDidUpdate(CGFloat);
	void
		setupTracker();

protected:
	/*NS_SYNTHESIZE
		(UIApplicationDelegate*,delegate);*/
	NITrackerManager* trackerManager;
	NITracker* torsoTracker;
	NITraceTracker* righthandTracker;
	NITraceTracker* lefthandTracker;
	NITracker* neckTracker;
	NS_SYNTHESIZE
		(CGFloat,rightCollarz);
	NS_SYNTHESIZE
		(CGFloat,rightCollarx);
	NS_SYNTHESIZE
		(CGFloat,rightCollary);
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
		(CGFloat ,shadowz);
	NS_SYNTHESIZE
		(CGFloat ,shadowzVelocity);
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
		(CGFloat ,t_lasthandx);
	NS_SYNTHESIZE
		(CGFloat ,t_lasthandy);
	bool newTouchSession;
	NS_SYNTHESIZE
		(UIWindow* , keyWindow);
	NS_SYNTHESIZE
		(NSMutableArray* , windows);
	NS_SYNTHESIZE
		(vid , scene);
NS_END;
int UIApplicationMain (
   int argc,
   char *argv[],
   NSString *principalClassName,
   NSString* delegateClassName
);