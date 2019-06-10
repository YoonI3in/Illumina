#include "MenuBackGround.h"

bool MenuBackGround::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	backImage = Sprite::create("Illumina.png");
	if (backImage == NULL)
	{
		return false;
	}
	backImage_Pos = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	backImage->setPosition(backImage_Pos);
	this->addChild(backImage, 0);

	this->scheduleUpdate();

	return true;
}