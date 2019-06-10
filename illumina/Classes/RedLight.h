#pragma once
#include <cocos2d.h>

USING_NS_CC;

class RedLight :public Layer
{
protected:
	Sprite*		redLight1;
	Sprite*		redLight2;
	Rect		redLight1_Rect;
	Rect		redLight2_Rect;
	Vec2		redLight1_Pos;
	Vec2		redLight2_Pos;

	Sprite*		red1;
	Sprite*		red2;
	Vec2		red1_Pos;
	Vec2		red2_Pos;

	bool		once = false;
public:
	CREATE_FUNC(RedLight);

	virtual bool init();

	virtual void update(float _dt);

	virtual void onMouseDown(cocos2d::Event* event);

};