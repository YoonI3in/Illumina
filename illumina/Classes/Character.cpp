#include "Character.h"
#include "TestManager.h"
#include "InputManager.h"
#include "SceneBase.h"
#include "Boxes.h"
#include "Box.h"
#include "Mirrors.h"
#include "Mirror.h"

bool Character::init()
{

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Motion.plist");

	character = Sprite::createWithSpriteFrameName("StandR.png");
	if (character == NULL)
	{
		return false;
	}
	if (TestManager::getInstance()->currentStage == 1) {
		char_Pos = Vec2(200, 64);
	}
	else if (TestManager::getInstance()->currentStage == 2) {
		char_Pos = Vec2(200,64);
	}
	else if (TestManager::getInstance()->currentStage == 3) {
		char_Pos = Vec2(64, 513);
	}
	else if (TestManager::getInstance()->currentStage == 4) {
		char_Pos = Vec2(32, 64);
	}
	else if (TestManager::getInstance()->currentStage == 5) {
		char_Pos = Vec2(32, 64);
	}
	else if (TestManager::getInstance()->currentStage == 6) {
		char_Pos = Vec2(62, 64);
	}
	
	character->setPosition(char_Pos);
	character->setAnchorPoint(Point(0.5, 0.03));
	this->addChild(character);
	this->scheduleUpdate();

	/*auto animation = Animation::create();
	animation->setDelayPerUnit(0.1);

	for (int i = 0; i < 16; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("Walk%d.png", i+1));

		if (frame == nullptr)
		{
			CCLOG("Load filed : ");
		}

		animation->addSpriteFrame(frame);
	}

	auto animate = Animate::create(animation);

	auto ac = RepeatForever::create(animate);
	character->runAction(ac);*/

	auto char_Keylistener = EventListenerKeyboard::create();

	char_Keylistener->onKeyPressed  = CC_CALLBACK_2(Character::onKeyPressed, this);

	char_Keylistener->onKeyReleased = CC_CALLBACK_2(Character::onKeyReleased, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(char_Keylistener, this);

	return true;
}

void Character::update(float _dt)
{
	for (int i = 0; i < 2; i++)
	{
		char_Motion[i] = Animation::create();
		char_Motion[i]->setDelayPerUnit(0.1f);
		for (int j = 0; j < 13; j++)
		{
			char_Frame[i] = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("Walk%d.png", (i*13)+j+1));
			if (char_Frame == nullptr)
			{
				CCLOG("Load failed");
			}
			char_Motion[i]->addSpriteFrame(char_Frame[i]);
		}
		char_Animate[i] = Animate::create(char_Motion[i]);
		char_RepeatForever[i] = RepeatForever::create(char_Animate[i]);
		char_RepeatForever[i]->setTag(i);
	}


	for (int a = 0; a < 2; a++)
	{
		jump_Motion[a] = Animation::create();
		jump_Motion[a]->setDelayPerUnit(0.14f);
		for (int b = 0; b < 5; b++)
		{
			jump_Frame[a] = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("Jump%d.png", (a * 7) + b + 1));
			if (jump_Frame[a] == nullptr)
			{
				CCLOG("Load failed");
			}
			jump_Motion[a]->addSpriteFrame(jump_Frame[a]);
		}
		jump_Animate[a] = Animate::create(jump_Motion[a]);
		jump_Repeat[a] = Repeat::create(jump_Animate[a], 1);

	}

	CFootHold result;
	CFootHold result2;

	CFootHold rightWallResult;
	CFootHold leftWallResult;

	Scene* scene				= Director::getInstance()->getRunningScene();
		
	SceneBase* sceneBase		= (SceneBase*)scene;  //Çüº¯È¯

	CFootHoldTree* tree			= sceneBase->GetFootHoldTree();
	
	bool isGravity			= false;
	bool hasRightWall		= tree->FindWall(Vec2(char_Pos.x + 19, char_Pos.y), Vec2(char_Pos.x + 19, char_Pos.y + 100), rightWallResult, true);
	bool hasLeftWall		= tree->FindWall(Vec2(char_Pos.x - 19, char_Pos.y), Vec2(char_Pos.x - 19, char_Pos.y + 100), leftWallResult, false);

	bool hasGround			= false;
	bool hasGround2			= false;

	hasGround				= tree->FindBelow(Vec2(char_Pos.x + 17, char_Pos.y), result);
	hasGround2				= tree->FindBelow(Vec2(char_Pos.x - 17, char_Pos.y), result2);

	if (hasGround == false && hasGround2 == true)
	{
		result = result2;
		hasGround = true;
	}
	else if (hasGround == true && hasGround2 == false)
	{

	}
	else if (hasGround && hasGround2)
	{
		if (result.getFirstPosY() < result2.getFirstPosY())
		{
			result = result2;
		}
	}

	{

		if (hasGround)
		{
			if (char_Pos.y > result.getFirstPosY())
				isGravity = true;
		}
		else
		{
			isGravity = true;
		}

		if (isGravity == true)
		{
			if (is_Jumpingup == true)
			{
				isGravity = false;
			}
		}

		if (isGravity)
		{
			if (isGravity == true && TestManager::getInstance()->holding == 1)
			{
				TestManager::getInstance()->pick = 1;
			}

			isFalling = true;
			float prev = -((jumpdownTime - 9)*(jumpdownTime - 9)) + 81;
			jumpdownTime += _dt * 20.0f;
			float current = -((jumpdownTime - 9)*(jumpdownTime - 9)) + 81;

			if (jumpdownTime >= 18.0f)
			{
				jumpdownTime = 18.0f;
			}

			char_Pos.y += current - prev;

			if (hasGround)
			{
				if (char_Pos.y < result.getFirstPosY())
				{
					char_Pos.y = result.getFirstPosY();
					jumpdownTime = 9.0f;
					isFalling = false;
					temp = false;
					
				}
			}
			is_Jumpingup = false;
		}
		else if (!hasGround)
		{

		}

	}
 

	if ((char_Key&KEYUP) == KEYUP)
	{
		if (is_Jumpingup == false && char_Pos.y == result.getFirstPosY())
		{
			/*if (isLanded == false)
			{
				character->setSpriteFrame("StandR.png");
			}*/ 
			
		}
		else if (is_Jumpingup == true)
		{
			/*character->stopActionByTag(0);
			character->stopActionByTag(1);
			if (playJump == true && temp == false)
			{
				temp = true;
				if (rightDir == true && leftDir == false)
				{
					character->runAction(jump_Repeat[0]);
				}
				else if (rightDir == false && leftDir == true)
				{
					character->runAction(jump_Repeat[1]);
				}
				
			}*/
			
			float prev = -((jumpupTime - 9)*(jumpupTime - 9)) + 81;
			jumpupTime += _dt*20.0f;
			float current = -((jumpupTime - 9)*(jumpupTime - 9)) + 81;

			if (jumpupTime >= 9.0f)
			{
				is_Jumpingup = false;
				jumpupTime = 0.0f;
				jumpdownTime = 9.0f;
				playJump = false;
			}
			char_Pos.y += current - prev;
		}
		
	}

	if (GlobalIntputManager->IsKeyDown(EventKeyboard::KeyCode::KEY_RIGHT_ARROW) == true)
	{
		moveSpeed = 150.0f;

		isGoingRight = true;

		leftDir = false;
		rightDir = true;

		if (isGoingRight == true)
		{
			char_Pos.x += moveSpeed*_dt;

			if (walkRight == true)
			{
				character->runAction(char_RepeatForever[0]);
			}
			walkRight = false;
		}

		if (hasRightWall)
		{
			if ((char_Pos.x + 19) >= rightWallResult.getFirstPosX())
			{
				char_Pos.x = rightWallResult.getFirstPosX() - 19.1;
			}
		}

		
	}

	if (GlobalIntputManager->IsKeyDown(EventKeyboard::KeyCode::KEY_LEFT_ARROW) == true)
	{
		moveSpeed = 150.0f;

		isGoingLeft = true;

		leftDir = true;
		rightDir = false;

		if (isGoingLeft == true)
		{
			char_Pos.x -= moveSpeed*_dt;

			if (walkLeft == true)
			{
				character->runAction(char_RepeatForever[1]);
			}
			
			walkLeft = false;
		}

		if (hasLeftWall)
		{
			if ((char_Pos.x - 19) <= leftWallResult.getFirstPosX())
			{
				char_Pos.x = leftWallResult.getFirstPosX() + 19.1;
			}
		}
	}

	if (GlobalIntputManager->IsKeyDown(EventKeyboard::KeyCode::KEY_RIGHT_ARROW) == false)
	{
		
		if (walkRight == false)
		{
			walkRight = true;
			character->stopActionByTag(0);
			character->setSpriteFrame("StandR.png");

		}
		
	}

	if (GlobalIntputManager->IsKeyDown(EventKeyboard::KeyCode::KEY_LEFT_ARROW) == false)
	{

		if (walkLeft == false)
		{
			walkLeft = true;
			character->stopActionByTag(1);
			character->setSpriteFrame("StandL.png");

		}

	}


	//Rect char_Rect = Rect(char_Pos.x - 22, char_Pos.y + 3, char_Pos.x + 22, char_Pos.y + 55);

	
	character->setPosition(char_Pos);
}

void Character::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		if (isFalling == false)
		{
			char_Key = char_Key | KEYUP;
			is_Jumpingup = true;
			isFalling = true;
			
		}
		playJump = true;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		//TestManager::getInstance()->_target = nullptr;
		TestManager::getInstance()->space = 1;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_CTRL)
	{

	}

	character->setPosition(char_Pos);
}

void Character::onKeyReleased(EventKeyboard::KeyCode keyCode, Event*event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{

	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		TestManager::getInstance()->space = 0;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_CTRL && TestManager::getInstance()->pick == 0)
	{

		Rect char_Rect = Rect(char_Pos.x - 22, char_Pos.y + 3, 44, 55);

		if (TestManager::getInstance()->_boxLayer != nullptr)
		{
			Vector<Node*> boxes = TestManager::getInstance()->_boxLayer->getChildren();

			for (int i = 0; i < boxes.size(); ++i)
			{
				Rect boxRect = boxes.at(i)->getBoundingBox();
				if (boxRect.intersectsRect(char_Rect))
				{
					TestManager::getInstance()->pick = 1;
					TestManager::getInstance()->_currentPickBox = (Box*)boxes.at(i);
					TestManager::getInstance()->_currentPickBox->DeleteFootHold();
					TestManager::getInstance()->_target = character;
					TestManager::getInstance()->holding = 1;
					break;
				}
			}
		}
		else if (TestManager::getInstance()->_boxLayer == nullptr)
		{

		}

		if (TestManager::getInstance()->_mirrorLayer != nullptr)
		{
			Vector<Node*> mirrors = TestManager::getInstance()->_mirrorLayer->getChildren();

			for (int j = 0; j < mirrors.size(); ++j)
			{
				Rect mirrorRect = mirrors.at(j)->getBoundingBox();
				if (mirrorRect.intersectsRect(char_Rect))
				{
					TestManager::getInstance()->pick = 1;
					TestManager::getInstance()->_currentPickMirror = (Mirror*)mirrors.at(j);
					TestManager::getInstance()->_target = character;
					TestManager::getInstance()->holding = 1;
					break;
				}
			}
		}
		
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_CTRL && TestManager::getInstance()->pick == 1 && is_Jumpingup == false && isFalling == false )
	{
		TestManager::getInstance()->pick = 0;
		TestManager::getInstance()->holding = 0;
	}

	character->setPosition(char_Pos);
}


Rect Character::BoundingBox()
{
	Rect char_Rect = character->getBoundingBox();

	return char_Rect;
}
