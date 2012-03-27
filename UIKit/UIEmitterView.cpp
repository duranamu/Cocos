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
#include <UIKit/UIEmitterView.h>
#include <UIKit/UIImage.h>
	UIEmitterView::UIEmitterView()
{
	self->content = new CCTexture2D();
}
UIEmitterView*
	UIEmitterView::initWithStyle(UIEmitterViewStyle style)
{
	self->emitterStyle = style;
	CCParticleSystem* particleSystem ;
		switch(self->emitterStyle)
	{
		case UIEmitterViewStyleExplosion :
			particleSystem = CCParticleExplosion::node();
		break;
		case UIEmitterViewStyleFire :
			particleSystem = CCParticleFire::node();
		break;
		case UIEmitterViewStyleFireworks :
			particleSystem = CCParticleFireworks::node();
		break;
		case UIEmitterViewStyleFlower :
			particleSystem = CCParticleFlower::node();
		break;
		case UIEmitterViewStyleGalaxy :
			particleSystem = CCParticleGalaxy::node();
		break;
		case UIEmitterViewStyleMeteor :
			particleSystem = CCParticleMeteor::node();
		break;
		case UIEmitterViewStyleRain :
			particleSystem = CCParticleRain::node();
		break;
		case UIEmitterViewStyleSmoke :
			particleSystem = CCParticleSmoke::node();
		break;
		case UIEmitterViewStyleSnow :
			particleSystem = CCParticleSnow::node();
		break;
		case UIEmitterViewStyleSpiral :
			particleSystem = CCParticleSpiral::node();
		break;
		case UIEmitterViewStyleSun :
			particleSystem = CCParticleSun::node();
		break;
		default:
			particleSystem = CCParticleMeteor::node();
	}
	self->ref = particleSystem;
	UIImage* defaultUIEmitterViewParticle = UIImage::imageNamed(NSSTR("defaultUIEmitterViewParticle.png"));
	if(defaultUIEmitterViewParticle)
	{
		self->ref->setTexture(defaultUIEmitterViewParticle->CGImage());
	}
	self->node = self->ref;
	return self;
}
UIEmitterView*
	UIEmitterView::viewWithStyle(UIEmitterViewStyle style)
{
	return (UIEmitterView*) alloc()->initWithStyle(style)->autorelease();
}
void
UIEmitterView::dealloc()
{
		self->ref->release();
		self->ref = nil;
}
void
	UIEmitterView::setcontent(CGImage* image)
{
	image->retain();
	self->content->release();
	self->content = image;

	self->ref->setTexture(image);
}
void
	UIEmitterView::setbirthRate(CGFloat rate)
{
	self->ref->setSpeed(rate);
}
void
	UIEmitterView::setscale(CGFloat aScale)
{
	ref->setScale(aScale);
}