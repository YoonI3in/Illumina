#include "Stage2Tile.h"

bool Stage2Tile::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	stage2Tile = Sprite::create("Stage2/Stage2Tile.png");

	stage2Tile->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(stage2Tile);
	this->scheduleUpdate();

	return true;
}