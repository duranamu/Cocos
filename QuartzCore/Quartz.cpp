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
#include "Quartz.h"
#include <math.h>
CGFloat PIOverOne = 1 / 3.1415926;
CGFloat radiantoAngleFactor = PIOverOne * 180.0f;
CGFloat 
	CGDistanceMake(CGPoint pa ,CGPoint pb)
{
	CGFloat x = fabsf(pa.x-pb.x);
	CGFloat y = fabsf(pa.y-pb.y);
	return sqrt(x*x+y*y);
}
CGFloat 
	CGAngleMake(CIVector* va , CIVector* vb)
{
	CGFloat dimension3 = va->getX()* vb->getY() - va->getY() * vb->getX();
	CGFloat sign =  dimension3 > 0 ? -1 : 1; 
	CGFloat radian = acos ((CGDotProduct2D (va , vb) / ( va->normOfVector2D() * vb->normOfVector2D() ) ) ) * sign ;
	return radian * radiantoAngleFactor;
}
CGFloat 
	CGRadianMake(CIVector* va , CIVector* vb)
{
	CGFloat dimension3 = va->getX()* vb->getY() - va->getY() * vb->getX();
	CGFloat sign =  dimension3 > 0 ? -1 : 1; 
	CGFloat radian = acos ((CGDotProduct2D (va , vb) / ( va->normOfVector2D() * vb->normOfVector2D() ) ) ) * sign;
	return radian;
}
inline CGFloat
	CGDotProduct2D(CIVector* va ,CIVector* vb)
{
	return va->getX() * vb->getX() +  va->getY() * vb->getY();
}