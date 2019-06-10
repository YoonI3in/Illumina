#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Button :public Sprite
{
protected:
	bool DoDeleteFoothold = false;

	int buttonIndex = -1;
public:
	CREATE_FUNC(Button);

	virtual bool init();

	void Setting(int index);

	void PressedSetting(int index);

	void DeleteFootHold();

	virtual void update(float _dt);
};