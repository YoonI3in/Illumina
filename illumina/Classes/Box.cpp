#include "Box.h"
#include "TestManager.h"
#include "InputManager.h"
#include "SceneBase.h"

bool Box::init()
{
	initWithFile("Box.png");

	scheduleUpdate();

	return true;
}

void Box::Setting(int index)
{
	boxIndex = index;
	SceneBase* sceneBase = (SceneBase*)this->getParent()->getParent();
	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	auto box_Rect = getBoundingBox();

	Vec2 leftTop( (int)(box_Rect.origin.x), (int)(box_Rect.origin.y + box_Rect.size.height));
	Vec2 rightTop((int)(box_Rect.origin.x + box_Rect.size.width), (int)(box_Rect.origin.y + box_Rect.size.height));
	CFootHold hold(leftTop, rightTop, index);
	tree->InsertTree(hold);
}

void Box::DeleteFootHold()
{
	SceneBase* sceneBase = (SceneBase*)this->getParent()->getParent();

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	tree->deleteHoldWithIndex(boxIndex);
}


void Box::update(float _dt)
{

	/*auto box_Pos.x = this->getPosition().x;
	auto box_YPos = this->getPosition().y;*/
	Vec2 box_Pos = this->getPosition();

	CFootHold result;
	CFootHold result2;
	CFootHold result3;

	Scene* scene = Director::getInstance()->getRunningScene();

	SceneBase* sceneBase = (SceneBase*)scene;  //Çüº¯È¯

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	float halfWidth = getContentSize().width / 2;

	float halfHeight = getContentSize().height / 2;

	if (TestManager::getInstance()->_currentPickBox != this)
	{
		bool isGravity = false;
		bool hasGround = false;
		bool hasGround2 = false;
		bool hasGround3 = false;

		hasGround = tree->FindBelow(Vec2(box_Pos.x - halfWidth, box_Pos.y - halfHeight), result);
		hasGround2 = tree->FindBelow(Vec2(box_Pos.x, box_Pos.y - halfHeight), result2);
		hasGround3 = tree->FindBelow(Vec2(box_Pos.x + halfWidth, box_Pos.y - halfHeight), result3);

		if (hasGround == false && hasGround2 == true && hasGround3 == true)
		{
			result = result2;
			hasGround = true;
		}
		else if (hasGround == true && hasGround2 == false && hasGround3 == true)
		{
			result2 = result;
			hasGround2 = true;
		}
		else if (hasGround == true && hasGround2 == true && hasGround3 == false)
		{
			result3 = result2;
			hasGround3 = true;
		}
		else if (hasGround == false && hasGround2 == false && hasGround3 == true)
		{
			result = result3;
			result2 = result3;
			hasGround = true;
			hasGround2 = true;
		}
		else if (hasGround == false && hasGround2 == true && hasGround3 == false)
		{
			result = result2;
			result3 = result2;
			hasGround = true;
			hasGround3 = true;
		}
		else if (hasGround == true && hasGround2 == false && hasGround3 == false)
		{
			result2 = result;
			result3 = result;
			hasGround2 = true;
			hasGround3 = true;
		}
		else if (hasGround && hasGround2 && hasGround3)
		{
			if (result.getFirstPosY() < result2.getFirstPosY())
			{
				result = result2;
			}
			else if (result.getFirstPosY() < result3.getFirstPosY())
			{
				result = result3;
			}
			else if (result2.getFirstPosY() < result.getFirstPosY())
			{
				result2 = result;
			}
			else if (result2.getFirstPosY() < result3.getFirstPosY())
			{
				result2 = result3;
			}
			else if (result3.getFirstPosY() < result.getFirstPosY())
			{
				result3 = result;
			}
			else if (result3.getFirstPosY() < result2.getFirstPosY())
			{
				result3 = result2;
			}
		}
		else
		{
			isGravity = true;
		}

		/*else if (hasGround && hasGround2)
		{
			if (result.getFirstPosY() < result2.getFirstPosY())
			{
				result = result2;
			}
			else if (result.getFirstPosY() > result2.getFirstPosY())
			{
				result2 = result;
			}
		}*/

		if (hasGround)
		{
			if (box_Pos.y - halfWidth  > result.getFirstPosY())
			{
				isGravity = true;
			}
		}
		else if (hasGround2)
		{
			if (box_Pos.y - halfWidth > result2.getFirstPosY())
			{
				isGravity = true;
			}
		}
		else if (hasGround3)
		{
			if (box_Pos.y - halfWidth > result3.getFirstPosY())
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
			if (DoDeleteFoothold == false)
			{
				tree->deleteHoldWithIndex(boxIndex);
				DoDeleteFoothold = true;
			}

			float prev = -((fallingDownTime - 9)*(fallingDownTime - 9)) + 81;
			fallingDownTime += _dt*20.0f;
			float current = -((fallingDownTime - 9)*(fallingDownTime - 9)) + 81;

			if (fallingDownTime >= 18.0f)
			{
				fallingDownTime = 18.0f;
			}

			box_Pos.y += current - prev;

			if (hasGround)
			{
				if (box_Pos.y - halfWidth  < result.getFirstPosY())
				{
					box_Pos.y = result.getFirstPosY() + halfHeight;
					fallingDownTime = 9.0f;
					DoDeleteFoothold = false;

					setPosition(box_Pos);
					Setting(boxIndex);
				}
			}
			else if (hasGround2)
			{
				if (box_Pos.y - halfWidth  < result2.getFirstPosY())
				{
					box_Pos.y = result2.getFirstPosY() + halfHeight;
					fallingDownTime = 9.0f;
					DoDeleteFoothold = false;

					setPosition(box_Pos);
					Setting(boxIndex);
				}
			}
			else if (hasGround3)
			{
				if (box_Pos.y - halfWidth  < result3.getFirstPosY())
				{
					box_Pos.y = result3.getFirstPosY() + halfHeight;
					fallingDownTime = 9.0f;
					DoDeleteFoothold = false;

					setPosition(box_Pos);
					Setting(boxIndex);
				}
			}

			setPosition(box_Pos);
		}
	}


	if (TestManager::getInstance()->_target != nullptr)
	{

		if (TestManager::getInstance()->pick == 1 && TestManager::getInstance()->_currentPickBox == this )
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
			
			flipBox();
		}
		else if (TestManager::getInstance()->pick == 0 && TestManager::getInstance()->_currentPickBox == this )
		{
			TestManager::getInstance()->_target = nullptr;
			TestManager::getInstance()->_currentPickBox = nullptr;
		}
		
	}
	

}

void Box::flipBox()
{
	auto targetXPos = (TestManager::getInstance()->_target)->getPosition().x;
	auto targetYPos = (TestManager::getInstance()->_target)->getPosition().y;

	if (isFlipped == 0)
	{
		this->setPosition(Point(targetXPos + 35, targetYPos + 60));
	}
	else if (isFlipped == 1)
	{
		this->setPosition(Point(targetXPos - 35, targetYPos + 60));
	}
}
