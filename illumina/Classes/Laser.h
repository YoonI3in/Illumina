#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Laser :public Layer
{
protected:
	Sprite*		laser1;
	Sprite*		laser2;
	Sprite*		laser3;
	Vec2		laser1_Pos;
	Vec2		laser2_Pos;
	Vec2		laser3_Pos;

	Sprite*		verticalLaserBeam1;
	Sprite*		verticalLaserBeam2;
	Sprite*		verticalLaserBeam3;

	Sprite*		horizontalLaserBeam1;
	Sprite*		horizontalLaserBeam2;
	Sprite*		horizontalLaserBeam3;


public:
	CREATE_FUNC(Laser);

	virtual bool init();

	virtual void update(float _dt);
};