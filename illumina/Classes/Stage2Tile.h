#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Stage2Tile :public Layer
{
protected:
	Sprite* stage2Tile;
public:
	CREATE_FUNC(Stage2Tile);

	virtual bool init();
};