#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Box;
class Boxes :public Layer
{
protected:
	Box*		box1Sprite;
	Box*		box2Sprite;
	Box*		box3Sprite;
	Box*		box4Sprite;
	Box*		box5Sprite;
	Box*		box6Sprite;
	Box*		box7Sprite;

public:
	CREATE_FUNC(Boxes);

	virtual bool init();
};