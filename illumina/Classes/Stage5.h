#pragma once
#include <cocos2d.h>
#include <SceneBase.h>

USING_NS_CC;

class Character;
class Stage5Tile;
class Laser;
class Recognizer;
class BlueLight;
class GreenLight;
class Mirrors;
class Boxes;
class Stage5 :public SceneBase
{
protected:
	Sprite*				backSprite;
	Sprite*				doorSprite;
	Sprite*				blockSprite;
	Stage5Tile*			tileLayer;
	Character*			charLayer;
	Laser*				laserLayer;
	Recognizer*			recognizerLayer;
	BlueLight*			blueLightLayer;
	GreenLight*			greenLightLayer;
	Mirrors*			mirrorsLayer;
	Boxes*				boxesLayer;

	bool				isDeleted = false;
	bool				isCreated = true;

public:
	static Scene* createScene();

	CREATE_FUNC(Stage5);
	
	virtual bool init();

	virtual void changeScene();

	virtual void update(float _dt);
};