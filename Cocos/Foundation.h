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
#ifndef _FOUNDATION_H
#define _FOUNDATION_H
#include <cocos2d.h>
#include <libxml\xpath.h>
#include <libxml\parser.h>
#define forCCArray( __array__)  do { CCObject* __object__; CCARRAY_FOREACH(__array__ , __object__){
#define eachCCObject(__VAR__ ,__INST__)  __VAR__ __INST__ = (__VAR__) __object__;
#define fetchCCObject(__VAR__ ,__INST__)  CCWrapper* __wrapper__ = (CCWrapper*)__object__; \
	__VAR__ __INST__ =  __wrapper__->data.__VAR__##Val
#define ccSynthesize(varType, varName)  CC_SYNTHESIZE(varType, varName, varName)  
#define ccProperty(varType, varName)  CC_PROPERTY(varType, varName, varName)  
#define forCCEnd  }}while(0);
#define CCS(__STR__) new CCString(__STR__)
#define nil NULL
#define ccSelector(__FUNC__) (SEL_CallFuncND)(&__FUNC__)
#define ccCast(__VAR__,__INST__) __VAR__ c##__INST__ = (__VAR__) __INST__;

#define forArray( __nsArray__ ) do { CCArray* __array__ = __nsArray__->ref ; \
	CCObject* __object__; CCARRAY_FOREACH(__array__ , __object__){
#define eachObject(__VAR__,__INST__)  __VAR__ __INST__ = (__VAR__) __object__;
#define forEnd   }}while(0);

#define For(__VAR__,__INST__,__NSARR__) forArray(__NSARR__) eachObject(__VAR__,__INST__)
#define ccFor(__VAR__,__INST__,__NSARR__) forCCArray(__NSARR__) eachObject(__VAR__,__INST__)

#define fordict(__VAR__,__INST__,__DICT__) \
	do{  __DICT__->ref->begin();__VAR__ __INST__;while(__INST__ = (__VAR__) __DICT__->ref->next()){	 

#define nss(__STR__) new NSString(__STR__)
#define vid void* 
#define self this

#define NSNotFound UINT_MAX;
#endif