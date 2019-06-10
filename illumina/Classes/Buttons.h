#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Button;
class Buttons :public Layer
{
protected:
	Button*		button1Sprite;
	Button*		button2Sprite;
	Button*		button3Sprite;
	Button*		button4Sprite;
	Button*		button5Sprite;
public:
	CREATE_FUNC(Buttons);

	virtual bool init();
};