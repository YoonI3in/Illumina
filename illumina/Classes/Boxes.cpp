#include "Boxes.h"
#include "TestManager.h"
#include "Box.h"

bool Boxes::init()
{
	

	

	/*box3Sprite = Box::create();
	this->addChild(box3Sprite);

	box4Sprite = Box::create();
	this->addChild(box4Sprite);

	box5Sprite = Box::create();
	this->addChild(box5Sprite);

	box6Sprite = Box::create();
	this->addChild(box6Sprite);

	box7Sprite = Box::create();
	this->addChild(box7Sprite);*/
	
	

	if (TestManager::getInstance()->currentStage == 1)
	{
		box1Sprite = Box::create();
		this->addChild(box1Sprite);

		box1Sprite->setPosition(416, 97);
	}
	else if (TestManager::getInstance()->currentStage == 2)
	{
		box1Sprite = Box::create();
		this->addChild(box1Sprite);

		box1Sprite->setPosition(512, 96);

		box2Sprite = Box::create();
		this->addChild(box2Sprite);

		box2Sprite->setPosition(1056, 96);

		box3Sprite = Box::create();
		this->addChild(box3Sprite);

		box3Sprite->setPosition(1056, 160);

		box4Sprite = Box::create();
		this->addChild(box4Sprite);

		box4Sprite->setPosition(1056, 224);

		box5Sprite = Box::create();
		this->addChild(box5Sprite);

		box5Sprite->setPosition(1056, 288);

		box6Sprite = Box::create();
		this->addChild(box6Sprite);

		box6Sprite->setPosition(1056, 352);
	}
	else if (TestManager::getInstance()->currentStage == 3)
	{
		box1Sprite = Box::create();
		this->addChild(box1Sprite);

		box1Sprite->setPosition(320, 546);

		box2Sprite = Box::create();
		this->addChild(box2Sprite);

		box2Sprite->setPosition(352, 98);

		box3Sprite = Box::create();
		this->addChild(box3Sprite);

		box3Sprite->setPosition(608, 162);

		box4Sprite = Box::create();
		this->addChild(box4Sprite);

		box4Sprite->setPosition(608, 418);

		box5Sprite = Box::create();
		this->addChild(box5Sprite);

		box5Sprite->setPosition(992, 290);

		box6Sprite = Box::create();
		this->addChild(box6Sprite);

		box6Sprite->setPosition(992, 354);
	}
	else if (TestManager::getInstance()->currentStage == 4)
	{
		
	}
	else if (TestManager::getInstance()->currentStage == 5)
	{
		box1Sprite = Box::create();
		this->addChild(box1Sprite);

		box1Sprite->setPosition(352, 160);

		box2Sprite = Box::create();
		this->addChild(box2Sprite);

		box2Sprite->setPosition(928, 96);
	}
	else if (TestManager::getInstance()->currentStage == 6)
	{

	}
	else if (TestManager::getInstance()->currentStage == 7)
	{

	}
	else if (TestManager::getInstance()->currentStage == 8)
	{

	}
	else if (TestManager::getInstance()->currentStage == 9)
	{

	}
	else if (TestManager::getInstance()->currentStage == 10)
	{

	}


	this->scheduleUpdate();

	return true;
}