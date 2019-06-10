#include "GreenLight.h"
#include "TestManager.h"

bool GreenLight::init()
{

	if (TestManager::getInstance()->currentStage == 5) {
		greenLight1 = Sprite::create("GreenLight.png");
		greenLight1_Pos = Vec2(448, 752);
		this->addChild(greenLight1, 1);

		green1 = Sprite::create("Stage5/Green.png");
		green1_Pos = Vec2(greenLight1_Pos.x -7, greenLight1_Pos.y - 15);
		green1->setAnchorPoint(Point(0.5, 1));
		green1->setVisible(false);
		this->addChild(green1, 0);
	}
	else if (TestManager::getInstance()->currentStage == 6) {
		greenLight1 = Sprite::create("GreenLight.png");
		greenLight1_Pos = Vec2(768, 752);
		this->addChild(greenLight1, 1);

		green1 = Sprite::create("Stage6/Green.png");
		green1_Pos = Vec2(greenLight1_Pos.x -7, greenLight1_Pos.y - 15);
		green1->setAnchorPoint(Point(0.5, 1));
		green1->setVisible(true);
		this->addChild(green1, 0);
	}
	else if (TestManager::getInstance()->currentStage == 8) {
		/*greenLight1 = Sprite::create("GreenLight.png");
		greenLight1_Pos = Vec2(928, 752);
		greenLight1->setPosition(greenLight1_Pos);
		this->addChild(greenLight1, 1);

		green1 = Sprite::create("Stage6/Green.png");
		green1_Pos = Vec2(greenLight1_Pos.x + 1, greenLight1_Pos.y - 15);
		green1->setAnchorPoint(Point(0.5, 1));
		green1->setVisible(true);
		this->addChild(green1, 0);*/
	}
	else if (TestManager::getInstance()->currentStage == 11) {
		greenLight1 = Sprite::create("GreenLight.png");
		greenLight1_Pos = Vec2(480, 752);
		this->addChild(greenLight1, 1);

		green1 = Sprite::create("Stage11/Green.png");
		green1_Pos = Vec2(greenLight1_Pos.x + 1, greenLight1_Pos.y - 15);
		green1->setAnchorPoint(Point(0.5, 1));
		green1->setVisible(true);
		this->addChild(green1, 0);

		greenLight2 = Sprite::create("GreenLight.png");
		greenLight2_Pos = Vec2(928, 688);
		this->addChild(greenLight2, 1);

		green2 = Sprite::create("Stage11/Green.png");
		green2_Pos = Vec2(greenLight2_Pos.x + 1, greenLight2_Pos.y - 15);
		green2->setAnchorPoint(Point(0.5, 1));
		green2->setVisible(true);
		this->addChild(green2, 0);
	}

	TestManager::getInstance()->_green1 = green1;
	//TestManager::getInstance()->_green2 = green2;

	greenLight1->setPosition(greenLight1_Pos);
	//greenLight2->setPosition(greenLight2_Pos);

	green1->setPosition(green1_Pos);
	//green1->setPosition(green2_Pos);

	auto Mouse = EventListenerMouse::create();

	Mouse->onMouseDown = CC_CALLBACK_1(GreenLight::onMouseDown, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(Mouse, this);

	this->scheduleUpdate();

	return true;
}

void GreenLight::onMouseDown(cocos2d::Event* event)
{
	auto greenLight_Rect = greenLight1->getBoundingBox();
	auto mouseEvent = static_cast<EventMouse*>(event);
	Vec2 ClickPoint = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
	auto mouseButton = mouseEvent->getMouseButton();


	if (TestManager::getInstance()->currentStage == 5) {

		if (greenLight_Rect.containsPoint(ClickPoint) && TestManager::getInstance()->greenOn == 0 && mouseButton == 0)
		{
			green1->setVisible(true);

			TestManager::getInstance()->greenOn = 1;
		}
		else if (greenLight_Rect.containsPoint(ClickPoint) && TestManager::getInstance()->greenOn == 1 && mouseButton == 0)
		{
			green1->setVisible(false);

			TestManager::getInstance()->greenOn = 0;
		}
	}
	
}