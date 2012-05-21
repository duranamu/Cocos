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
#include <QuartzCore/CAEmitterCell.h>
	CAEmitterCell::CAEmitterCell()
{
	self->content = new CCTexture2D();
}

CAEmitterCell*
	CAEmitterCell::initWithStyle(CAEmitterCellStyle style)
{
	self->emitterStyle = style;
	CCParticleSystem* particleSystem ;
		switch(self->emitterStyle)
	{
		case CAEmitterCellStyleExplosion :
		particleSystem = CCParticleExplosion::node();
		break;
		case CAEmitterCellStyleFire :
		particleSystem = CCParticleFire::node();
		break;
		case CAEmitterCellStyleFireworks :
		particleSystem = CCParticleFireworks::node();
		break;
		case CAEmitterCellStyleFlower :
		particleSystem = CCParticleFlower::node();
		break;
		case CAEmitterCellStyleGalaxy :
		particleSystem = CCParticleGalaxy::node();
		break;
		case CAEmitterCellStyleMeteor :
		particleSystem = CCParticleMeteor::node();
		break;
		case CAEmitterCellStyleRain :
		particleSystem = CCParticleRain::node();
		break;
		case CAEmitterCellStyleSmoke :
		particleSystem = CCParticleSmoke::node();
		break;
		case CAEmitterCellStyleSnow :
		particleSystem = CCParticleSnow::node();
		break;
		case CAEmitterCellStyleSpiral :
		particleSystem = CCParticleSpiral::node();
		break;
		case CAEmitterCellStyleSun :
		particleSystem = CCParticleSun::node();
		break;
	}
	self->ref = particleSystem;
	return self;
}
CAEmitterCell*
	CAEmitterCell::cellWithStyle(CAEmitterCellStyle style)
{
	return (CAEmitterCell*) alloc()->initWithStyle(style)->autorelease();
}
void
CAEmitterCell::dealloc()
{
		self->ref->release();
		self->ref = nil;
}
void
	CAEmitterCell::setcontent(CGImage* image)
{
	image->retain();
	self->content->release();
	self->content = image;

	self->ref->setTexture(image);
}
void
	CAEmitterCell::setbirthRate(CGFloat rate)
{
	self->ref->setSpeed(rate);
}
void
	CAEmitterCell::setscale(CGFloat aScale)
{
	ref->setScale(aScale);
}