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
#include <UIKit/UIView.h>
typedef enum UIEmitterViewStyle
{
	UIEmitterViewStyleExplosion , //CCParticleExplosion
	UIEmitterViewStyleFire  ,     //CCParticleFire
	UIEmitterViewStyleFireworks , //CCParticleFireworks
	UIEmitterViewStyleFlower ,    //CCParticleFlower
	UIEmitterViewStyleGalaxy ,    //CCParticleGalaxy
	UIEmitterViewStyleMeteor ,    //CCParticleMeteor
	UIEmitterViewStyleRain   ,    //CCParticleRain
	UIEmitterViewStyleSmoke  ,    //CCParticleSmoke
	UIEmitterViewStyleSnow   ,    //CCParticleSnow
	UIEmitterViewStyleSpiral ,    //CCParticleSpiral
	UIEmitterViewStyleSun    ,     //CCParticleSun
	UIEmitterViewStyleDefault = UIEmitterViewStyleGalaxy
};
NS_INTERFACE(UIEmitterView,UIView)
	NS_HAS_REF(CCParticleSystem*,ref);
	public:
	UIEmitterView();
	 UIEmitterView*
		 initWithStyle(UIEmitterViewStyle);
	static  UIEmitterView*
		viewWithStyle(UIEmitterViewStyle);
	protected:
		CGImage* content;
		CGFloat birthRate;
		CGFloat scale;
		UIEmitterViewStyle emitterStyle;
	public:
	void
		setscale(CGFloat );
	CGFloat 
		getscale(){ self->scale = ref->getScale(); return self->scale;}
	CGFloat
		getbirthRate(){self->birthRate = ref->getSpeed(); return self->birthRate;}
	void
		setbirthRate(CGFloat);
	CGImage* 
		getcontent(){return self->content;}
	void
		setcontent(CGImage* );
NS_END