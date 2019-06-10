#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Box :public Sprite
{
protected:
	bool		isFlipped;
	bool		DoDeleteFoothold = false;

	int boxIndex = -1;

	float fallingDownTime = 9.0f;
public:
	CREATE_FUNC(Box);

	virtual bool init();

	void Setting(int index);

	void DeleteFootHold();

	virtual void update(float _dt);

	virtual void flipBox();
};