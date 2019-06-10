#include "Buttons.h"
#include "TestManager.h"
#include "Button.h"

bool Buttons::init()
{
	if (TestManager::getInstance()->currentStage == 2)
	{
		button1Sprite = Button::create();
		button1Sprite->setAnchorPoint(Point(0.5, 0));
		this->addChild(button1Sprite);
		
		button1Sprite->setPosition(352, 64);
	}
	else if (TestManager::getInstance()->currentStage == 3)
	{
		button1Sprite = Button::create();
		button1Sprite->setAnchorPoint(Point(0.5, 0));
		this->addChild(button1Sprite);

		button1Sprite->setPosition(192, 513);

		button2Sprite = Button::create();
		button2Sprite->setAnchorPoint(Point(0.5, 0));
		this->addChild(button2Sprite);

		button2Sprite->setPosition(224, 65);
	}
	else if (TestManager::getInstance()->currentStage == 6)
	{

	}
	else if (TestManager::getInstance()->currentStage == 8)
	{

	}
	else if (TestManager::getInstance()->currentStage == 11)
	{

	}

	return true;
}