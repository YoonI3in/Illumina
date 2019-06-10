#pragma once
#include <cocos2d.h>

USING_NS_CC;

class BlueLight :public Layer
{
protected:
	Sprite*		blueLight1;
	Sprite*		blueLight2;
	Rect		blueLight1_Rect;
	Rect		blueLight2_Rect;
	Vec2		blueLight1_Pos;
	Vec2		blueLight2_Pos;

	Sprite*		blue1;
	Sprite*		blue2;
	Vec2		blue1_Pos;
	Vec2		blue2_Pos;

	bool		once = false;
public:
	CREATE_FUNC(BlueLight);

	virtual bool init();

	//virtual void update(float _dt);

	virtual void onMouseDown(cocos2d::Event* event);

};