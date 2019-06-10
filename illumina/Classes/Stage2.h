#pragma once
#include <cocos2d.h>
#include "SceneBase.h"

USING_NS_CC;

class Character;
//class Door;
class RedLight;
class Stage2Tile;
class Boxes;
class Buttons;
class Stage2 :public SceneBase
{
protected:
	Sprite*				backSprite;
	Sprite*				blockSprite;
	Character*			charLayer;
	Stage2Tile*			tileLayer;
	//Door*				doorSprite;
	RedLight*			redLightLayer;
	Boxes*				boxesLayer;
	Buttons*			buttonsLayer;

	bool				isDeleted = false;
	bool				isCreated = true;

	int buttonIndex		= 250;
	
public:	
	static Scene* createScene();

	CREATE_FUNC(Stage2);

	virtual bool init();

	virtual void update(float _dt);

	virtual void changeScene();
};