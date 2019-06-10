#include "Mirrors.h"
#include "TestManager.h"
#include "Mirror.h"

bool Mirrors::init()
{
	if (TestManager::getInstance()->currentStage == 1)
	{

	}
	else if (TestManager::getInstance()->currentStage == 2)
	{

	}
	else if (TestManager::getInstance()->currentStage == 3)
	{

	}
	else if (TestManager::getInstance()->currentStage == 4)
	{
		mirror1Sprite = Mirror::create();
		this->addChild(mirror1Sprite);

		mirror1Sprite->setPosition(352,288);
	}
	else if (TestManager::getInstance()->currentStage == 5)
	{
		mirror1Sprite = Mirror::create();
		this->addChild(mirror1Sprite);

		mirror1Sprite->setPosition(1120, 352);
	}
	else if (TestManager::getInstance()->currentStage == 6)
	{
		mirror1Sprite = Mirror::create();
		this->addChild(mirror1Sprite);

		mirror1Sprite->setPosition(288, 158);
	}
	this->scheduleUpdate();

	return true;
}