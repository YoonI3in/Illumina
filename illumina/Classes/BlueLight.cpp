#include "BlueLight.h"
#include "TestManager.h"

bool BlueLight::init()
{
	if (TestManager::getInstance()->currentStage == 5)
	{
		blueLight1 = Sprite::create("BlueLight.png");
		blueLight1_Pos = Vec2(256, 752);
		this->addChild(blueLight1, 1);

		blue1 = Sprite::create("Stage5/Blue.png");
		blue1_Pos = Vec2(blueLight1_Pos.x - 7, blueLight1_Pos.y - 15);
		blue1->setAnchorPoint(Point(0.5, 1));
		blue1->setVisible(true);
		this->addChild(blue1, 0);
	}
	else if (TestManager::getInstance()->currentStage == 10) {
		blueLight1 = Sprite::create("BlueLight.png");
		blueLight1_Pos = Vec2(288, 752);
		this->addChild(blueLight1, 1);

		blue1 = Sprite::create("Stage9/Blue.png");
		blue1_Pos = Vec2(blueLight1_Pos.x - 7, blueLight1_Pos.y - 15);
		blue1->setAnchorPoint(Point(0.5, 1));
		blue1->setVisible(false);
		this->addChild(blue1, 0);
	}
	else if (TestManager::getInstance()->currentStage == 11) {
		blueLight1 = Sprite::create("BlueLight.png");
		blueLight1_Pos = Vec2(352, 752);
		this->addChild(blueLight1, 1);

		blue1 = Sprite::create("Stage9/Blue.png");
		blue1_Pos = Vec2(blueLight1_Pos.x - 7, blueLight1_Pos.y - 15);
		blue1->setAnchorPoint(Point(0.5, 1));
		blue1->setVisible(false);
		this->addChild(blue1, 0);

		/*blueLight2 = Sprite::create("BlueLight.png");
		blueLight2_Pos = Vec2(800, 752);
		this->addChild(blueLight2, 1);

		blue2 = Sprite::create("Stage11/Blue.png");
		blue2_Pos = Vec2(blueLight2_Pos.x + 1, blueLight2_Pos.y - 15);
		blue2->setAnchorPoint(Point(0.5, 1));
		blue2->setVisible(false);
		this->addChild(blue2, 0);*/
	}

	TestManager::getInstance()->_blue1 = blue1;
	//TestManager::getInstance()->_blue2 = blue2;

	blueLight1->setPosition(blueLight1_Pos);

	blue1->setPosition(blue1_Pos);

	auto Mouse = EventListenerMouse::create();

	Mouse->onMouseDown = CC_CALLBACK_1(BlueLight::onMouseDown, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(Mouse, this);

	this->scheduleUpdate();

	return true;
}

void BlueLight::onMouseDown(cocos2d::Event* event)
{
	auto blueLight_Rect = blueLight1->getBoundingBox();
	auto mouseEvent = static_cast<EventMouse*>(event);
	Vec2 ClickPoint = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
	auto mouseButton = mouseEvent->getMouseButton();

	if (TestManager::getInstance()->currentStage == 10) {

		if (blueLight_Rect.containsPoint(ClickPoint) && TestManager::getInstance()->blueOn == 0 && mouseButton == 0)
		{
			blue1->setVisible(true);

			TestManager::getInstance()->blueOn = 1;
		}
		else if (blueLight_Rect.containsPoint(ClickPoint) && TestManager::getInstance()->blueOn == 1 && mouseButton == 0)
		{
			blue1->setVisible(false);

			TestManager::getInstance()->blueOn = 0;
		}
	}
}