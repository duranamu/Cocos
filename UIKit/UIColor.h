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
#include <QuartzCore/QuartzCore.h>
NS_INTERFACE( UIColor , NSObject)
	UIColor*
		initWithRed_blue_green_alpha(CGFloat ,CGFloat, CGFloat,CGFloat);
	static UIColor*
		colorWithRed_blue_green_alpha(CGFloat ,CGFloat, CGFloat,CGFloat);
	static const UIColor*
		redColor();
	static const UIColor*
		yellowColor();
	static const UIColor*
		cyanColor();
	static const UIColor*
		purpleColor();
	static const UIColor*
		blackColor();
	static const UIColor*
		brownColor();
	static const UIColor*
		greenColor();
	static const UIColor*
		magentaColor();
	static const UIColor*
		orangeColor();
	static const UIColor*
		whiteColor();
	protected:
	NS_SYNTHESIZE
		(ccColor4F , color4f );
	NS_SYNTHESIZE
		(ccColor3B , color3b );
	NS_SYNTHESIZE
		(CGFloat , alpha );
NS_END