#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Mirror;
class Mirrors :public Layer
{
protected:
	Mirror*			mirror1Sprite;
	Mirror*			mirror2Sprite;
	Mirror*			mirror3Sprite;

public:
	CREATE_FUNC(Mirrors);

	virtual bool init();
};