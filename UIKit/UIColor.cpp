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
#include "UIColor.h"
NS_STATIC_ALLOC(UIColor);
const UIColor*	UIRedColor = UIColor::colorWithRed_blue_green_alpha(1.0f ,0.0f , 0.0f ,1.0f);
const UIColor*  UICyanColor = UIColor::colorWithRed_blue_green_alpha(0.0f ,1.0f , 1.0f ,1.0f);
const UIColor*  UIPurpleColor = UIColor::colorWithRed_blue_green_alpha(0.5f ,0.0f , 0.5f ,1.0f);
const UIColor*  UIBlackColor = UIColor::colorWithRed_blue_green_alpha(0.0f ,0.0f , 0.0f ,1.0f);
const UIColor*  UIBrownColor = UIColor::colorWithRed_blue_green_alpha(0.6f ,0.4f , 0.2f ,1.0f);
const UIColor*  UIGreenColor = UIColor::colorWithRed_blue_green_alpha(0.0f ,1.0f , 0.0f ,1.0f);
const UIColor*  UIMagentaColor = UIColor::colorWithRed_blue_green_alpha(1.0f ,0.0f , 1.0f ,1.0f);
const UIColor*  UIOrangeColor = UIColor::colorWithRed_blue_green_alpha(1.0f ,0.5f , 0.0f ,1.0f);
const UIColor*  UIWhiteColor = UIColor::colorWithRed_blue_green_alpha(1.0f ,1.0f , 1.0f ,1.0f);
const UIColor*  UIYellowColor = UIColor::colorWithRed_blue_green_alpha(1.0f ,1.0f , 0.0f ,1.0f);
UIColor*
	UIColor::initWithRed_blue_green_alpha(CGFloat redf ,CGFloat bluef, CGFloat greenf, CGFloat alphaf)
{
	self->color3b = ccc3(redf*255 ,bluef*255 ,greenf*255 );
	self->alpha = alphaf;
	self->color4f = ccc4FFromccc4B( ccc4(redf*255 ,bluef*255 ,greenf*255,alphaf*255) );

	return self;
}
UIColor*
	UIColor::colorWithRed_blue_green_alpha(CGFloat redf ,CGFloat bluef, CGFloat greenf, CGFloat alphaf)
{
	return alloc()->initWithRed_blue_green_alpha(redf , bluef , greenf , alphaf);
}
const UIColor*
	UIColor::redColor()
{
	return UIRedColor;
}
const UIColor*
	UIColor::yellowColor()
{
	return UIYellowColor;
}
const UIColor*
	UIColor::cyanColor()
{
	return UICyanColor;
}
const UIColor*
	UIColor::purpleColor()
{
	return UIPurpleColor;
}
const UIColor*
	UIColor::blackColor()
{
	return UIBlackColor;
}
const UIColor*
	UIColor::brownColor()
{
	return UIBrownColor;
}
const UIColor*
	UIColor::greenColor()
{
	return UIGreenColor;
}
const UIColor*
	UIColor::magentaColor()
{
	return UIMagentaColor;
}
const UIColor*
	UIColor::orangeColor()
{
	return UIOrangeColor;
}
const UIColor*
	UIColor::whiteColor()
{
	return UIWhiteColor;
}


