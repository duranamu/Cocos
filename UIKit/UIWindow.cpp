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
#include "UIWindow.h"
#include "UIApplication.h"
void
	UIWindow::becomeKeyWindow()
{
	self->keyWindow = YES;
}
void
	UIWindow::makeKeyAndVisible()
{
	UIApplication::sharedApplication()->addWindow(self);
	self->becomeKeyWindow();
	self->hidden = NO;
}
void
	UIWindow::sendEvent(UIEvent* evt)
{
	UIEventType type = evt->gettype();
	if(type == UIEventTypeTouches)
	{
		UITouch* touch = (UITouch*)evt->gettouches()->anyObject();
		UITouchPhase phase = touch->getphase();
		switch(phase)
		{
		case UITouchPhaseBegan:
			{
				self->rootViewController->touchesBegan_withEvent(evt->gettouches(),evt);
				break;
			}
		case UITouchPhaseMoved:
			{
				self->rootViewController->touchesMoved_withEvent(evt->gettouches(),evt);
				break;
			}
		case UITouchPhaseEnded:
			{
				self->rootViewController->touchesEnded_withEvent(evt->gettouches(),evt);
				break;
			}
		}
	}
}
NS_STATIC_ALLOC(UIWindow)
NS_INSTANCE_INIT(UIWindow)