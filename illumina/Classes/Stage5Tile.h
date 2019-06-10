#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Stage5Tile :public Layer
{
protected:
	Sprite* stage5Tile;
public:
	CREATE_FUNC(Stage5Tile);

	virtual bool init();
};