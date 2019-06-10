#include "RedLight.h"
#include "TestManager.h"

bool RedLight::init()
{
	/*redLight1 = Sprite::create("RedLight.png");
	this->addChild(redLight1,1);*/

	if (TestManager::getInstance()->currentStage == 1) {
		redLight1 = Sprite::create("RedLight.png");
		redLight1_Pos = Vec2(990, 684);
		this->addChild(redLight1, 1);

		red1 = Sprite::create("Stage1/Red.png");
		red1_Pos = Vec2(redLight1_Pos.x + 1, redLight1_Pos.y - 15);
		red1->setAnchorPoint(Point(0.5, 1));
		red1->setVisible(false);
		this->addChild(red1, 0);
	}
	else if (TestManager::getInstance()->currentStage == 2) {
		redLight1 = Sprite::create("RedLight.png");
		redLight1_Pos = Vec2(1120, 752);
		this->addChild(redLight1, 1);

		red1 = Sprite::create("Stage2/Red.png");
		red1_Pos = Vec2(redLight1_Pos.x - 7, redLight1_Pos.y - 15);
		red1->setAnchorPoint(Point(0.5, 1));
		red1->setVisible(true);
		if (TestManager::getInstance()->red1On == 1)
		{
			red1->setVisible(true);
		}
		else if (TestManager::getInstance()->red1On == 0)
		{
			red1->setVisible(false);
		}
		this->addChild(red1, 0);
	}
	else if (TestManager::getInstance()->currentStage == 3) {
		redLight1 = Sprite::create("RedLight.png");
		redLight1_Pos = Vec2(192, 752);
		this->addChild(redLight1, 1);

		red1 = Sprite::create("Stage3/Red.png");
		red1_Pos = Vec2(redLight1_Pos.x - 7, redLight1_Pos.y - 15);
		red1->setAnchorPoint(Point(0.5, 1));
		red1->setVisible(false);
		this->addChild(red1, 0);
	}
	else if (TestManager::getInstance()->currentStage == 4) {
		redLight1 = Sprite::create("RedLight.png");
		redLight1_Pos = Vec2(640, 752);
		this->addChild(redLight1, 1);

		red1 = Sprite::create("Stage4/Red.png");
		red1_Pos = Vec2(redLight1_Pos.x - 7, redLight1_Pos.y - 15);
		red1->setAnchorPoint(Point(0.5, 1));
		red1->setVisible(false);
		this->addChild(red1, 0);
	}
	else if (TestManager::getInstance()->currentStage == 5) {
	
	}
	else if (TestManager::getInstance()->currentStage == 6) {
		redLight1 = Sprite::create("RedLight.png");
		redLight1_Pos = Vec2(384, 752);
		this->addChild(redLight1, 1);

		red1 = Sprite::create("Stage6/Red.png");
		red1_Pos = Vec2(redLight1_Pos.x + 1, redLight1_Pos.y - 15);
		red1->setAnchorPoint(Point(0.5, 1));
		red1->setVisible(true);
		this->addChild(red1, 0);
	}
	else if (TestManager::getInstance()->currentStage == 7) {
		redLight1 = Sprite::create("RedLight.png");
		redLight1_Pos = Vec2(608, 752);
		this->addChild(redLight1, 1);

		red1 = Sprite::create("Stage5/Red1.png");
		red1_Pos = Vec2(redLight1_Pos.x - 7, redLight1_Pos.y - 15);
		red1->setAnchorPoint(Point(0.5, 1));
		red1->setVisible(false);
		this->addChild(red1, 0);

		redLight2 = Sprite::create("RedLight.png");
		redLight2_Pos = Vec2(1056, 752);
		redLight2->setPosition(redLight2_Pos);
		this->addChild(redLight2, 1);

		red2 = Sprite::create("Stage5/Red2.png");
		red2_Pos = Vec2(redLight2_Pos.x - 7, redLight2_Pos.y - 15);
		red2->setPosition(red2_Pos);
		red2->setAnchorPoint(Point(0.5, 1));
		red2->setVisible(false);
		this->addChild(red2, 0);
	}
	else if (TestManager::getInstance()->currentStage == 8) {
		/*redLight1 = Sprite::create("RedLight.png");
		redLight1_Pos = Vec2(608, 752);
		redLight1->setPosition(redLight1_Pos);
		this->addChild(redLight1, 1);

		red1 = Sprite::create("Stage5/Red1.png");
		red1_Pos = Vec2(redLight1_Pos.x - 7, redLight1_Pos.y - 15);
		red1->setAnchorPoint(Point(0.5, 1));
		red1->setVisible(false);
		this->addChild(red1, 0);*/
	}
	else if (TestManager::getInstance()->currentStage == 11) {
		redLight1 = Sprite::create("RedLight.png");
		redLight1_Pos = Vec2(640, 688);
		this->addChild(redLight1, 1);

		red1 = Sprite::create("Stage11/Red.png");
		red1_Pos = Vec2(redLight1_Pos.x - 7, redLight1_Pos.y - 15);
		red1->setAnchorPoint(Point(0.5, 1));
		red1->setVisible(false);
		this->addChild(red1, 0);
	}


	TestManager::getInstance()->_red1 = red1;
	//TestManager::getInstance()->_red2 = red2;

	redLight1->setPosition(redLight1_Pos);

	red1				->setPosition(red1_Pos);

	auto Mouse			= EventListenerMouse::create();

	Mouse->onMouseDown	= CC_CALLBACK_1(RedLight::onMouseDown, this);

	_eventDispatcher	->addEventListenerWithSceneGraphPriority(Mouse, this);

	this->scheduleUpdate();

	return true;
}

void RedLight::update(float _dt)
{
	if (TestManager::getInstance()->currentStage == 2)
	{
		if (TestManager::getInstance()->red1On == 1)
		{
			red1->setVisible(true);
		}
		else if (TestManager::getInstance()->red1On == 0)
		{
			red1->setVisible(false);
		}
	}
	else if (TestManager::getInstance()->currentStage == 3)
	{
		if (TestManager::getInstance()->red1On == 1)
		{
			red1->setVisible(true);
		}
		else if (TestManager::getInstance()->red1On == 0)
		{
			red1->setVisible(false);
		}
	}
}

void RedLight::onMouseDown(cocos2d::Event* event)
{
	auto redLight_Rect	= redLight1->getBoundingBox();
	auto mouseEvent		= static_cast<EventMouse*>(event);
	Vec2 ClickPoint		= Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
	auto mouseButton	= mouseEvent->getMouseButton();

	if (TestManager::getInstance()->currentStage == 1) 
	{
		if (redLight_Rect.containsPoint(ClickPoint) && TestManager::getInstance()->red1On == 0)
		{
			if (mouseButton == 0)
			{
				red1->setVisible(true);

				TestManager::getInstance()->red1On = 1;
			}
		}
		else if (redLight_Rect.containsPoint(ClickPoint) && TestManager::getInstance()->red1On == 1)
		{
			if (mouseButton == 0)
			{
				red1->setVisible(false);

				TestManager::getInstance()->red1On = 0;
			}
		}
	}
}
