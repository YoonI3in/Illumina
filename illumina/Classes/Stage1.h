#pragma once
#include <cocos2d.h>
#include "SceneBase.h"

USING_NS_CC;

class Character;
class Boxes;
class RedLight;
class Stage1 :public SceneBase
{
protected:
	Sprite*				backSprite;
	Sprite*				blockSprite;
	Character*			charLayer;
	RedLight*			redLightLayer;
	Boxes*				boxesLayer;
		
	bool				isDeleted = false;
	bool				isCreated = true;
public:
	virtual ~Stage1();

	static Scene* createScene();

	CREATE_FUNC(Stage1);

	virtual bool init();

	virtual void changeScene();

	virtual void update(float _dt);

};