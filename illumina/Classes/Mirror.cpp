#include "Mirror.h"
#include "TestManager.h"
#include "InputManager.h"
#include "SceneBase.h"

bool Mirror::init()
{
	initWithFile("Mirror.png");

	scheduleUpdate();

	return true;
}

void Mirror::Setting(int index)
{
	auto rect = getBoundingBox();
}

void Mirror::update(float _dt)
{
	Vec2 mirror_Pos = getPosition();

	CFootHold result;
	CFootHold result2;

	Scene* scene = Director::getInstance()->getRunningScene();

	SceneBase* sceneBase = (SceneBase*)scene;  //Çüº¯È¯

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	if (TestManager::getInstance()->_currentPickMirror != this)
	{
		bool isGravity = false;
		bool hasGround = false;
		bool hasGround2 = false;
		hasGround = tree->FindBelow(Vec2(mirror_Pos.x + 21, mirror_Pos.y - 30), result);
		hasGround2 = tree->FindBelow(Vec2(mirror_Pos.x - 21, mirror_Pos.y - 30), result2);

		if (hasGround == false && hasGround2 == true)
		{
			result = result2;
			hasGround = true;
		}
		else if (hasGround == true && hasGround2 == false)
		{

		}
		else if (hasGround&&hasGround2)
		{
			if (result.getFirstPosY() < result2.getFirstPosY())
			{
				result = result2;
			}
		}
		if (hasGround)
		{
			if (mirror_Pos.y - 30 > result.getFirstPosY())
			{
				isGravity = true;
			}
		}
		else
		{
			isGravity = true;
		}

		if (isGravity == true)
		{
			float prev = -((fallingDownTime - 9)*(fallingDownTime - 9)) + 81;
			fallingDownTime += _dt*20.0f;
			float current = -((fallingDownTime - 9)*(fallingDownTime - 9)) + 81;

			if (fallingDownTime >= 18.0f)
			{
				fallingDownTime = 18.0f;
			}
			mirror_Pos.y += current - prev;

			if (hasGround)
			{
				if (mirror_Pos.y - 30 < result.getFirstPosY())
				{
					mirror_Pos.y = result.getFirstPosY() + 30;
					fallingDownTime = 9.0f;
				}
			}
			setPosition(mirror_Pos);
		}
	}


	if (TestManager::getInstance()->_target != nullptr)
	{
		if (TestManager::getInstance()->pick == 1 && TestManager::getInstance()->_currentPickMirror == this)
		{
			if (GlobalIntputManager->IsKeyDown(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
			{
				isFlipped = 0;
				this->setFlippedX(false);
			}
			if (GlobalIntputManager->IsKeyDown(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
			{
				isFlipped = 1;
				this->setFlippedX(true);
			}

			flipMirror();
		}
		else if (TestManager::getInstance()->pick == 0 && TestManager::getInstance()->_currentPickMirror == this)
		{
			TestManager::getInstance()->_target = nullptr;
			TestManager::getInstance()->_currentPickMirror = nullptr;
		}
	}
}

void Mirror::flipMirror()
{
	auto targetXPos = (TestManager::getInstance()->_target)->getPosition().x;
	auto targetYPos = (TestManager::getInstance()->_target)->getPosition().y;

	if (isFlipped == 0)
	{
		this->setPosition(Point(targetXPos + 35, targetYPos + 60));
		TestManager::getInstance()->rightDir = 1;
	}
	else if (isFlipped == 1)
	{
		this->setPosition(Point(targetXPos - 35, targetYPos + 60));
		TestManager::getInstance()->rightDir = 0;
	}
}