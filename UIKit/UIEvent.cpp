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
#include "UIEvent.h"
_set* 
	UIEvent::allTouches()
{
	return touches;
}
NS_STATIC_ALLOC(UIEvent);
UIEvent*
	UIEvent::initWithTouches(_set* set)
{
	self->touches = set;
	return self;
}
UIEvent*
	UIEvent::eventWithTouches(_set* set)
{
	UIEvent* mem = alloc();
	if(mem && mem->initWithTouches(set))
	{

	}else{
		NS_SAFE_DELETE(mem);
	}
	return mem;
}
UIEvent*
	UIEvent::eventWithTouches_type(_set* set ,UIEventType type)
{
	UIEvent* mem ;
	mem = eventWithTouches(set);
	mem->settype(type);
	return mem;
}