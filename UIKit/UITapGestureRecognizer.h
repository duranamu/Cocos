/****************************************************************************

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
#ifndef UITAPGESTURERECOGNIZER_H
#define UITAPGESTURERECOGNIZER_H
#include "..\Cocos\Cocos.h"
#include "UIEvent.h"
#include "UIGestureRecognizer.h"
class UITapGestureRecognizer :public UIGestureRecognizer 
{
protected:
	ccSynthesize (NSUInteger ,numberOfTapsRequired );
	ccSynthesize (NSUInteger ,numberOfTapsAcquired );
	ccSynthesize (float ,tapStartTime );
	ccSynthesize (float ,tapStartX );
	ccSynthesize (float ,tapStartY );
public:
	static UITapGestureRecognizer*
		alloc();
	UITapGestureRecognizer*
		initWithTarget_action(SelectorProtocol* ,SEL_CallFuncND);
	UITapGestureRecognizer();
	virtual void 
		 touchesBegin_withEvent(CCSet* touches ,UIEvent* events);
	 virtual void 
		 touchesMoved_withEvent(CCSet* touches ,UIEvent* events);
	 virtual void 
		 touchesEnded_withEvent(CCSet* touches ,UIEvent* events);
};
#endif