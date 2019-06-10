#pragma once
#include <cocos2d.h>
#include <SceneBase.h>

USING_NS_CC;

class Character;
class Stage6Tile;
class RedLight;
class GreenLight;
class Laser;
class Recognizer;
class Mirrors;
class Stage6 :public SceneBase
{
protected:
	Sprite*			backSprite;
	Sprite*			blockSprite1;
	Sprite*			blockSprite2;
	Stage6Tile*		tileLayer;
	Character*		charLayer;
	RedLight*		redLightLayer;
	GreenLight*		greenLightLayer;
	Laser*			laserLayer;
	Recognizer*		recognizerLayer;
	Mirrors*		mirrorsLayer;

	bool			isRedDeleted = false;
	bool			isRedCreated = true;
	bool			isGreenDeleted = false;
	bool			isGreenCreated = true;
	
public:
	static Scene* createScene();

	CREATE_FUNC(Stage6);

	virtual bool init();

	virtual void update(float _dt);

	//virtual void changeScene();
};