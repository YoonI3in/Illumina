#pragma once
#include <cocos2d.h>

USING_NS_CC;

class GreenLight :public Layer
{
protected:
	Sprite*		greenLight1;
	Sprite*		greenLight2;
	Rect		greenLight1_Rect;
	Rect		greenLight2_Rect;
	Vec2		greenLight1_Pos;
	Vec2		greenLight2_Pos;

	Sprite*		green1;
	Sprite*		green2;
	Vec2		green1_Pos; 
	Vec2		green2_Pos;

public:
	CREATE_FUNC(GreenLight);

	virtual bool init();

	//virtual void update(float _dt);

	virtual void onMouseDown(cocos2d::Event* event);
};