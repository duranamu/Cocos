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
#include <UIKit/UITouch.h>
UITouch*
	UITouch::touchWithPhase(UITouchPhase phase)
{
	return (UITouch*) alloc()->initWithPhase(phase)->autorelease();
}
	UITouch::UITouch()
{
	//self->gestureRecognizers = NSMutableArray::alloc()->init();
}
CGPoint
	UITouch::locationInView()
{
	return location;
}
UITouch*
	UITouch::initWithPhase(UITouchPhase pphase)
{
	phase = pphase;
	return self;
}
void
	UITouch::dealloc()
{
	//if(self->m_bManaged == false)
	//{
	//self->gestureRecognizers->release();
	//self->gestureRecognizers = nil;
	//}
}
void
	UITouch::objectDidLoad()
{
	self->gestureRecognizers = NSMutableArray::alloc()->init();
}
void
	UITouch::objectDidUnload()
{
	self->gestureRecognizers->release();
	self->gestureRecognizers = nil;
}
NS_CACHE_OBJECT_INIT(UITouch)