/****************************************************************************
	UIKit OpenSource Project
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
#include "UINavigationController.h"
NS_STATIC_ALLOC(UINavigationController);
UINavigationController*
	UINavigationController::initWithRootViewController
	(UIViewController* rootViewController)
{
	self->rootViewController = rootViewController;
	self->pushViewController_viewController_animated(rootViewController,YES);
	return self;
}
	UINavigationController::UINavigationController()
{
	self->stackPointer = 0;
	self->viewControllers =NSArray::array();
}
void 
	UINavigationController::pushViewController_viewController_animated
	(UIViewController* p_rootViewController , BOOL animated)
{
	self->viewControllers->addObject(p_rootViewController);
	self->stackPointer++;
	self->view = p_rootViewController->view;
	self->topViewController = p_rootViewController;
}
void
	UINavigationController::viewDidLoad()
{
	self->topViewController->viewDidLoad();
}
void
	UINavigationController::viewDidUpdate(CGFloat time)
{
	self->topViewController->viewDidUpdate(time);
}
void
	UINavigationController::predo_controller_torsoData(CCNode * node , vid sender)
{
	self->topViewController->predo_controller_torsoData(node ,sender);
}