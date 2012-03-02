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
#include <Cocos/Cocos.h>
#include <UIKit/UIWindow.h>
NS_CLASS UIEvent;
class UIApplication : public CCLayerColor ,public UIView
{
public:
	void 
		predo_controller_torsoData(CCNode*,vid);
	void 
		predo_controller_righthandData(CCNode* ,vid);
	void
		predo_controller_lefthandData(CCNode*, vid);
	UITouchPhase 
		touchPhaseforTime_handz(CGFloat,CGFloat);
	void 
		addWindow(UIWindow*);
	void
		selectKeyWindow();

	static UIApplication*
		sharedApplication();
	static UIApplication*
		alloc();
	UIApplication*
		init();
	UIApplication();
	void
		senEvent(UIEvent*);
	void
		applicationDidUpdate(CGFloat);

protected:
	NITrackerManager* trackerManager;
	NITracker* torsoTracker;
	NITracker* righthandTracker;
	NITracker* lefthandTracker;
	ccSynthesize
		(CGFloat ,g_lasthandz);
	ccSynthesize
		(CGFloat ,g_lasthandzVelocity);
	ccSynthesize
		(CGFloat ,m_handz);
	ccSynthesize
		(CGFloat ,m_handx);
	ccSynthesize
		(CGFloat ,m_handy);
	ccSynthesize
		(CGFloat ,gl_lasthandz);
	ccSynthesize
		(CGFloat ,gl_lasthandzVelocity);
	ccSynthesize
		(CGFloat ,ml_handz);
	ccSynthesize
		(CGFloat ,ml_handx);
	ccSynthesize
		(CGFloat ,ml_handy);
	ccSynthesize
		(CGFloat ,m_torsox);
	ccSynthesize
		(CGFloat ,m_torsoy);
	ccSynthesize
		(BOOL ,isRighthandTracked);
		
	UITouchPhase menuTouchPhase;
	ccSynthesize
		(CGFloat ,touchStartx);
	ccSynthesize
		(CGFloat ,touchStarty);
	CGFloat touchStartTime;
	ccSynthesize
		(CGFloat ,t_lasthandx);
	ccSynthesize
		(CGFloat ,t_lasthandy);
	bool newTouchSession;
	ccSynthesize
		(UIWindow* , keyWindow);
	ccSynthesize
		(NSArray* , windows);
	ccSynthesize
		(vid , scene);
};
int UIApplicationMain (
   int argc,
   char *argv[],
   NSString *principalClassName,
   NSString *delegateClassName
);
