#pragma once
#include <cocos2d.h>
#include "SceneBase.h"

USING_NS_CC;

class Character;
class Stage3Tile;
class RedLight;
class Boxes;
class Buttons;
class Stage3 :public SceneBase
{
protected:
	Sprite*				backSprite;
	Sprite*				blockSprite;
	Sprite*				doorSprite;
	Stage3Tile*			tileLayer;
	Character*			charLayer;
	RedLight*			redLightLayer;
	Boxes*				boxesLayer;
	Buttons*			buttonsLayer;

	bool				isDeleted = false;
	bool				isCreated = true;

	int buttonIndex = 350;

public:

	static Scene* createScene();

	CREATE_FUNC(Stage3);

	virtual bool init();

	virtual void update(float _dt);

	virtual void changeScene();
};