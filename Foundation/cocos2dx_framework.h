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
#include <cocos2d.h>
using namespace cocos2d;
#include <libxml\xpath.h>
#include <libxml\parser.h>
#include <Foundation/NSObjCRuntime.h>
#include <Foundation/FoundationDataType.h>
#define forCCArray( __array__)  do { CCObject* __object__; CCARRAY_FOREACH(__array__ , __object__){
#define eachCCObject(__VAR__ ,__INST__)  __VAR__ __INST__ = (__VAR__) __object__;
#define fetchCCObject(__VAR__ ,__INST__)  CCWrapper* __wrapper__ = (CCWrapper*)__object__; \
	__VAR__ __INST__ =  __wrapper__->data.__VAR__##Val
#define ccSynthesize(varType, varName)  CC_SYNTHESIZE(varType, varName, varName)  

#define ccSynthesize_retain(varType,varName) \
protected: varType varName;\
public: inline varType get##varName(void) const { return varName; }\
public: inline void set##varName(varType var){var->retain(); varName->release();varName = var; }

#define ccSynthesize_copy(varType,varName) \
protected: varType varName;\
public: inline varType get##varName(void) const { return varName; }\
public: inline void set##varName(varType var){ varType cp = (varType)var->copy(); varName->release();varName = cp; }


#define ccProperty(varType, varName)  CC_PROPERTY(varType, varName, varName)  
#define forCCEnd  }}while(0);
#define CCS(__STR__) new CCString(__STR__)
#define nil NULL
#define ccSelector(__FUNC__) (SEL_CallFuncND)(&__FUNC__)
#define _cast(__VAR__,__INST__) __VAR__ c##__INST__ = (__VAR__) __INST__;
#define _super(__VAR__)  __VAR__ super = (__VAR__) self;
#define super(__VAR__) ((__VAR__)self)
#define vid void*
#define forArray( __nsArray__ ) do { CCArray* __array__ = __nsArray__->ref ; \
	CCObject* __object__; CCARRAY_FOREACH(__array__ , __object__){
#define eachObject(__VAR__,__INST__)  __VAR__ __INST__ = (__VAR__) __object__;
#define forEnd   }}while(0);

#define For(__VAR__,__INST__,__NSARR__) forArray(__NSARR__) eachObject(__VAR__,__INST__)
#define ccFor( __VAR__,__INST__,__NSARR__) forCCArray(__NSARR__) eachObject(__VAR__,__INST__)
#define ccForEnd  }}while(0);

#define fordict(__VAR__,__INST__,__DICT__) \
	do{  __DICT__->ref->begin();__VAR__ __INST__;while(__INST__ = (__VAR__) __DICT__->ref->next()){	 
#define fordictEnd }}while(0);

#define forSet(__var__ , __inst__ , _CCSet__) \
	do { CCSetIterator __it__ = _CCSet__->begin(); \
	while( (__it__) != _CCSet__->end()){          \
			__var__ __inst__ = (__var__ ) (*__it__); __it__++; if(!__inst__) break;

#define _s(__STR__)  NSString::stringWithCString_encoding(__STR__,NSASCIIStringEncoding)//new NSString(__STR__)
#define self this

#define NS_SAFE_DELETE(__PTR__) CC_SAFE_DELETE(__PTR__)
#define NSNotFound UINT_MAX;


#define YES 1
#define NO  0
//typedef int BOOL
typedef CCSet NSSet;
#define NS_STATIC_ALLOC(__var__) \
__var__*  __var__::alloc(){__var__* mem = new __var__();if(!mem){NS_SAFE_DELETE(mem);}return mem;}
#define NS_INSTANCE_INIT(__var__) __var__* __var__::init(){return self;}
#define NS_SINGLETON(__var__ ,__method__) \
static __var__* sharedInstance; __var__* __var__::__method__() \
{if(sharedInstance == nil){sharedInstance =  __var__::alloc()->init();}return sharedInstance;}

#define NS_ALLOC_FULL(__var__) \
static __var__* alloc(){__var__* mem = new __var__();if(!mem){NS_SAFE_DELETE(mem);}return mem;}

#define NS_INIT_FULL(__var__)  __var__* init(){return self;}

#define NS_DEALLOCATE(__var__)  void  dealloc(); ~__var__(){ self->dealloc();}

#define SEL SEL_CallFuncND
#define NSActionTarget SelectorProtocol

#define NS_INTERFACE(__class__,__super__)\
class __class__ : public __super__{ public:  NS_ALLOC_FULL(__class__) NS_INIT_FULL(__class__) NS_DEALLOCATE(__class__)
#define NS_END };


typedef void (*NSCodeBlock)(vid, vid , vid); 

#define NS_CLASS class
