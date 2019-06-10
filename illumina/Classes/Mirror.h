#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Mirror :public Sprite
{
protected:
	bool isFlipped;

	float fallingDownTime = 9.0f;
public:
	CREATE_FUNC(Mirror);
	
	virtual bool init();

	void Setting(int index);

	virtual void update(float _dt);

	virtual void flipMirror();
};