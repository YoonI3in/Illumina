#pragma once
#include <cocos2d.h>

USING_NS_CC;

class MenuBackGround :public Layer
{
protected:
	Sprite*		backImage;
	Vec2		backImage_Pos;
public:
	CREATE_FUNC(MenuBackGround);

	virtual bool init();
};