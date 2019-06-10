#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Door :public Sprite
{
protected:
	Sprite*		door;
	Vec2		door_Pos;
	Rect		door_Rect;
public:
	CREATE_FUNC(Door);

	virtual bool init();

	Rect BoundingBox();
};