#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Stage4Tile :public Layer
{
protected:
	Sprite* stage4Tile;
public:
	CREATE_FUNC(Stage4Tile);

	virtual bool init();
};