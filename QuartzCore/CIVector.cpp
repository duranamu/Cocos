/****************************************************************************
	Cocos OpenSource Project
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
#include "CIVector.h"
NS_STATIC_ALLOC(CIVector);
CIVector*
	CIVector::vectorFrom_to(CGPoint pa , CGPoint pb)
{
	CIVector* mem = alloc();
	mem->initFrom_to(pa,pb);
	return mem;
}
CIVector*
	CIVector::initFrom_to(CGPoint pa , CGPoint pb)
{
	self->X = pb.x - pa.x ;
	self->Y = pb.y - pa.y ;
	return self;
}
CIVector*
	CIVector::vectorWithCGPoint(CGPoint pa)
{
	CIVector* mem = alloc();
	mem->initWithCGPoint(pa);
	return mem;
}
CIVector*
	CIVector::initWithCGPoint(CGPoint pa )
{
	self->X = pa.x;
	self->Y = pa.y;
	return self;
}
CIVector*
	CIVector::addVector(CIVector * vec)
{
	self->X += vec->getX();
	self->Y += vec->getY();
	return self;
}