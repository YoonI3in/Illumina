#include"Door.h"
#include "TestManager.h"

bool Door::init()
{
	door = Sprite::create("Door.png");
	if (door == NULL)
	{
		return false;
	}
	if (TestManager::getInstance()->currentStage == 1) {
		door_Pos = Vec2(600, 113);
	}
	else if (TestManager::getInstance()->currentStage == 2) {
		door_Pos = Vec2(947, 150);
	}
	door->setPosition(door_Pos);
	door->setAnchorPoint(Point(0.5, 0));
	this->addChild(door);
	this->scheduleUpdate();

	return true;
}

Rect Door::BoundingBox()
{
	Rect door_Rect = door->getBoundingBox();
	return door_Rect;
}