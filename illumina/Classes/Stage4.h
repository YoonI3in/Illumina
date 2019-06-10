#pragma once
#include <cocos2d.h>
#include "SceneBase.h"

USING_NS_CC;

class Character;
class Stage4Tile;
class Laser;
class Recognizer;
class RedLight;
class Mirrors;
class Stage4 :public SceneBase
{
protected:
	Sprite*				backSprite;
	Sprite*				doorSprite;
	Stage4Tile*			tileLayer;
	Character*			charLayer;
	Laser*				laserLayer;
	Recognizer*			recognizerLayer;
	RedLight*			redLightLayer;
	Mirrors*			mirrorsLayer;

	bool				isDeleted = false;
	bool				isCreated = true;

public:
	static Scene* createScene();

	CREATE_FUNC(Stage4);

	virtual bool init();

	virtual void changeScene();
	
	virtual void update(float _dt);
};