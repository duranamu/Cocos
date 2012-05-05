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
#include  <libxml/xpath.h>
#include <libxml/parser.h>
#include <Foundation/NSObjCRuntime.h>
#include <Foundation/FoundationDataType.h>

#define NS_SYNTHESIZE(varType,varName)  NS_SYNTHESIZE_ASSIGN(varType,varName)

#define NS_SYNTHESIZE_ASSIGN(varType,varName) \
protected: varType varName;\
public: inline varType get##varName(void) const { return varName; }\
public: inline void set##varName(varType var){ varName = var; }
#define NS_PROPERTY(varType,varName) \
protected: varType varName;\
public: virtual varType get##varName(void);\
public: virtual void set##varName(varType var);

#define NS_SYNTHESIZE_READONLY(varType,varName) CC_SYNTHESIZE_READONLY(varType, varName, varName) 

#define NS_SYNTHESIZE_RETAIN(varType,varName) \
protected: varType varName;\
public: inline varType get##varName(void)  { return varName; }\
public: inline void set##varName(varType var){var->retain(); varName->release();varName = var; }

#define NS_SYNTHESIZE_READONLY_RETAIN(varType,varName) \
protected: varType varName;\
public: inline varType get##varName(void)  { return varName; }\
private: inline void set##varName(varType var){var->retain(); varName->release();varName = var; }

#define NS_SYNTHESIZE_RETAIN_READONLY(varType,varName ) \
protected: varType varName; \
public: inline varType get##varName(void)  { return varName; }\
protected: inline void set##varName(varType var){var->retain(); varName->release();varName = var; }

#define NS_SYNTHESIZE_COPY(varType,varName) \
protected: varType varName;\
public: inline varType get##varName(void) const { return varName; }\
public: inline void set##varName(varType var){ varType cp = (varType)var->copy(); varName->release();varName = cp; }

#define nend  }}while(0);
#define CCS(__STR__) new CCString(__STR__)
#define NS_SELECTOR_PP(__FUNC__) (SEL_PP)(&__FUNC__)
#define NSCAST(__VAR__,__INST__) __VAR__ c##__INST__ = (__VAR__) __INST__;
#define vid void*

#define nfor(__var__,__inst__,__arr__)  do {NSFastEnumeration* __enu__ = (NSFastEnumeration*) __arr__; __enu__->gotoBeginObject();__var__ __inst__;while( (__inst__ = (__var__) __enu__->nextObject())!= NULL){

#define afor(__type__,__object__,__leading_argument__) do{va_list __argp__;__type__  __object__;va_start(__argp__ , __leading_argument__);while(__object__ = va_arg( __argp__ , __type__ )){
		
#define aend }va_end (__argp__);}while(0);

#define nfor_CCSet(__var__ , __inst__ , _NSSet__) \
	do { CCSetIterator __it__ = _NSSet__->begin(); \
	while( (__it__) != _NSSet__->end()){          \
			__var__ __inst__ = (__var__ ) (*__it__); __it__++; if(!__inst__) break;

#define NSSTR(__STR__)  NSString::stringWithCString_encoding(__STR__,NSASCIIStringEncoding)


#define NS_SAFE_DELETE(__PTR__) CC_SAFE_DELETE(__PTR__)

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

#define NSActionTarget NSSelectorProtocol

#define NS_INTERFACE(__class__,...)\
class __class__ : public __VA_ARGS__{ public: NS_ALLOC_FULL(__class__) NS_INIT_FULL(__class__) NS_DEALLOCATE(__class__)

#define NS_INTERFACE_ALLOC_SPEC(__class__,...)\
class __class__ : public __VA_ARGS__{ public: static __class__* alloc(); NS_INIT_FULL(__class__) NS_DEALLOCATE(__class__)

#define NS_IGNORE

#define NS_INTERFACE_INIT_SPEC(__class__,...)\
class __class__ : public __VA_ARGS__{ public:  NS_ALLOC_FULL(__class__)  NS_DEALLOCATE(__class__)

#define MAX_CACHE_OBJECT 50

#define NS_CACHE_ALLOC_FULL(__var__)  void inline objectDidLoad(); static __var__* alloc(){ __var__* mem ; \
			if(_cache == nil){return new __var__();} \
			if(_cache_count <= 0 ) {for (NSUInteger i = 0; i< MAX_CACHE_OBJECT ;i++) _cache[i] = new __var__(); \
				_cache_count = MAX_CACHE_OBJECT; _header =0;} \
			mem = _cache[_header]; _header = (_header++) % MAX_CACHE_OBJECT ; --_cache_count; \
			if(!mem){CC_SAFE_DELETE(mem);}else{mem->objectDidLoad();}return mem;}

#define NS_CACHE_OBJECT_RECYCLE(__class__) \
void inline objectDidUnload(); \
void inline objectDidRecycle(){_cache[--_header] = self;m_uReference++; _cache_count++; } \
void operator delete(void* pointer){ if(_header > 0){__class__* object = (__class__*) pointer;object->objectDidUnload();object->objectDidRecycle();}\
	else{ free(pointer);}}

#define NS_INIT(__var__)  __var__* init(){return self;}

#define NS_INTERFACE_CACHE(__class__,...)\
class __class__ : public __VA_ARGS__{static __class__** _cache; static NSUInteger _header ; static NSUInteger _cache_count ; \
public:  NS_INIT(__class__) NS_CACHE_ALLOC_FULL(__class__)  NS_DEALLOCATE(__class__)

#define NS_INTERFACE_DEBUG(__class__,...)\
class __class__ : public __VA_ARGS__{static __class__** _cache; static NSUInteger _header ; static NSUInteger _cache_count ; \
public:  NS_INIT(__class__) NS_DEALLOCATE(__class__) NS_CACHE_ALLOC_FULL(__class__) NS_CACHE_OBJECT_RECYCLE(__class__)

#define NS_ABSRTACT_INTERFACE(__class__,...)\
	class __class__:public __VA_ARGS__{ public:

#define NS_CACHE_CLEAR(_class_) 

#define NS_END };

#define NS_CACHE_OBJECT_INIT(__class__) \
	__class__** __class__::_cache = (__class__**) new __class__[MAX_CACHE_OBJECT][1]; \
	NSUInteger __class__::_header = 0; \
	NSUInteger __class__::_cache_count = 0; 

typedef void (*NSCodeBlock)(vid, vid , vid); 

#define NS_CLASS class

#define NS_PROTOCOL class

#define APPEND_CHAR(_root_char_,_extra_char_) _root_char_##,#_extra_char_ 

#define NS_PROTOCOL(__name__)  class __name__ { public:

#define NS_PROTOCOL_CONFORM(__class__,...) class __class__ :  __VA_ARGS__{ public: 

#define NS_HAS_REF(_ref_class_,_ref_object_) \
public: _ref_class_ _ref_object_; 

#define self this

#define NS_PRIVATE private:

#define NS_PLUS static

#define NS_DROP_EXTERN extern