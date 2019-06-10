#pragma once
#include <cocos2d.h>

USING_NS_CC;

class Recognizer :public Layer
{
protected:
	Sprite*		recognizer1;
	Sprite*		recognizer2;
	Sprite*		recognizer3;

public:
	CREATE_FUNC(Recognizer);

	virtual bool init();
};