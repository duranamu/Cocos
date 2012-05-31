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
#include <Foundation/NSOperationQueue.h>
static NSOperationQueue* _mainQueue;
void
	NSOperationQueue::dealloc()
{

}
NSOperationQueue*
	NSOperationQueue::initWithDispatchQueue(dispatch_queue_t hd)
{
	self->_dispatch_queue = hd;
	return self;
}
NSOperationQueue* 
	NSOperationQueue::mainQueue()
{
	if(_mainQueue == nil)
	{
		_mainQueue = alloc()->initWithDispatchQueue(
			dispatch_get_main_queue());
	}
	return _mainQueue;
}
void
	NSOperationQueue::addOperation(NSOperation* operation)
{
}
NSOperationQueue*
	NSOperationQueue::currentQueue()
{
	return alloc()->initWithDispatchQueue(
		dispatch_get_current_queue());
}