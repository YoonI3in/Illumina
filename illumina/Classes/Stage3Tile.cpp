#include "Stage3Tile.h"

bool Stage3Tile::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	stage3Tile = Sprite::create("Stage3/Stage3Tile.png");

	stage3Tile->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(stage3Tile);
	this->scheduleUpdate();

	return true;
}