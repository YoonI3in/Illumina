#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Stage6Tile :public Layer
{
protected:
	Sprite* stage6Tile;
public:
	CREATE_FUNC(Stage6Tile);

	virtual bool init();
};