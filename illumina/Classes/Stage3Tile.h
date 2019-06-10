#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Stage3Tile :public Layer
{
protected:
	Sprite* stage3Tile;
public:
	CREATE_FUNC(Stage3Tile);

	virtual bool init();
};