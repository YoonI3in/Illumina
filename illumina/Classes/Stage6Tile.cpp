#include "Stage6Tile.h"

bool Stage6Tile::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	stage6Tile = Sprite::create("Stage6/Stage6Tile.png");

	stage6Tile->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(stage6Tile);
	this->scheduleUpdate();

	return true;
}