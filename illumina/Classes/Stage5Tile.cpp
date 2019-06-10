#include "Stage5Tile.h"

bool Stage5Tile::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	stage5Tile = Sprite::create("Stage5/Stage5Tile.png");

	stage5Tile->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(stage5Tile);
	this->scheduleUpdate();

	return true;
}