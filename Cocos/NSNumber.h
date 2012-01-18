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
#ifndef NSNUMBER_H
#define NSNUMBER_H
#endif
#include <cocos2d.h>
#include <CCObject.h>
#include "NSObject.h"
using namespace cocos2d;
class NSNumber : public NSObject
{
public :
	 union {
		int intVal;
		char charVal;
		float floatVal;
		bool boolVal;
	}data;

	 NSNumber(char inVal)
	 {
		 data.charVal = inVal;
	 }
  static NSNumber* numberWithChar(char inVal)
  {
	  NSNumber* newVal = new NSNumber(inVal);
	  newVal->autorelease();
	  return newVal;
  }
  	 NSNumber(int inVal)
	 {
		 data.intVal = inVal;
	 }
  static NSNumber* numberWithInt(int inVal)
  {
	  NSNumber* newVal = new NSNumber(inVal);
	  newVal->autorelease();
	  return newVal;
  }
  	 NSNumber(float inVal)
	 {
		 data.floatVal = inVal;
	 }
  static NSNumber* numberWithFloat(float inVal)
  {
	  NSNumber* newVal = new NSNumber(inVal);
	  newVal->autorelease();
	  return newVal;
  }
  	 NSNumber(bool inVal)
	 {
		 data.boolVal = inVal;
	 }
  static NSNumber* numberWithBool(bool inVal)
  {
	  NSNumber* newVal = new NSNumber(inVal);
	  newVal->autorelease();
	  return newVal;
  }
};
