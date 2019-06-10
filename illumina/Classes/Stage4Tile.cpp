#include "Stage4Tile.h"

bool Stage4Tile::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	stage4Tile = Sprite::create("Stage4/Stage4Tile.png");

	stage4Tile->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(stage4Tile);
	this->scheduleUpdate();

	return true;
}