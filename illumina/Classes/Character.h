#pragma once
#include <cocos2d.h>
#include "FootHold.h"

#define KEYUP		0X0001
#define KEYDOWN		0X0010
#define KEYRIGHT	0X0100
#define KEYLEFT		0X1000

USING_NS_CC;

class Character :public Layer
{
protected:
	Sprite*			character;
	Vec2			char_Pos;
	Rect			char_Rect;

	Animation*		char_Motion[2];
	SpriteFrame*	char_Frame[2];
	Animate*		char_Animate[2];
	RepeatForever*	char_RepeatForever[2];

	Animation*		jump_Motion[2];
	SpriteFrame*	jump_Frame[2];
	Animate*		jump_Animate[2];
	Repeat*			jump_Repeat[2];

	int				char_Key;
	bool			is_Jumpingup		= false;
	bool			isFalling			= false;
	bool			walkRight			= true;
	bool			walkLeft			= true;
	bool			isGoingRight		= false;
	bool			isGoingLeft			= false;
	bool			isDeleted			= false;
	bool			isCreated			= true;
	bool			playJump			= true;
	bool			temp				= false;
	bool			isLanded			= false;
	bool			rightDir = true;
	bool			leftDir = false;
		
	float			moveSpeed			= 200.0f;
	float			jumpupTime			= 0.0f;
	float			jumpdownTime		= 9.0f;
		
public:
	CREATE_FUNC(Character);

	virtual bool init();

	virtual void update(float _dt);

	virtual void onKeyPressed	(EventKeyboard::KeyCode, Event* Code);

	virtual void onKeyReleased	(EventKeyboard::KeyCode, Event* Code);

	//virtual void lightWall();

	//virtual void walkAnimation();

	Rect BoundingBox();
};