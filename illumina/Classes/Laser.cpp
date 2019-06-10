#include "Laser.h"
#include "Recognizer.h"
#include "TestManager.h"

bool Laser::init()
{

	if (TestManager::getInstance()->currentStage == 4) {
		laser1 = Sprite::create("Laser.png");
		this->addChild(laser1, 1);

		laser1_Pos = Vec2(416, 739);
		laser1->setPosition(laser1_Pos);

		verticalLaserBeam1 = Sprite::create("LaserBeam.png");
		verticalLaserBeam1->setPosition(laser1_Pos.x, laser1_Pos.y - 20);
		verticalLaserBeam1->setAnchorPoint(Point(0.5, 1));
		this->addChild(verticalLaserBeam1, 0);

		horizontalLaserBeam1 = Sprite::create("LaserBeam.png");
		horizontalLaserBeam1->setPosition(laser1_Pos.x, 279);
		horizontalLaserBeam1->setAnchorPoint(Point(0, 0.5));
		this->addChild(horizontalLaserBeam1, 0);

		
		laser2 = Sprite::create("Laser.png");
		this->addChild(laser2, 1);
		
		laser2_Pos = Vec2(864, 739);
		laser2->setPosition(laser2_Pos);

		verticalLaserBeam2 = Sprite::create("LaserBeam.png");
		verticalLaserBeam2->setPosition(laser2_Pos.x, laser1_Pos.y - 20);
		verticalLaserBeam2->setAnchorPoint(Point(0.5, 1));
		this->addChild(verticalLaserBeam2, 0);

		horizontalLaserBeam2 = Sprite::create("LaserBeam.png");
		horizontalLaserBeam2->setPosition(laser2_Pos.x, 279);
		horizontalLaserBeam2->setAnchorPoint(Point(0, 0.5));
		this->addChild(horizontalLaserBeam2, 0);

		TestManager::getInstance()->_verticalLaser2 = verticalLaserBeam2;
		TestManager::getInstance()->_horizontalLaser2 = horizontalLaserBeam2;

	}

	else if (TestManager::getInstance()->currentStage == 5)
	{
		laser1 = Sprite::create("Laser.png");
		this->addChild(laser1, 1);

		laser1_Pos = Vec2(96, 739);
		laser1->setPosition(laser1_Pos);

		verticalLaserBeam1 = Sprite::create("LaserBeam.png");
		verticalLaserBeam1->setPosition(laser1_Pos.x, laser1_Pos.y - 20);
		verticalLaserBeam1->setAnchorPoint(Point(0.5, 1));
		this->addChild(verticalLaserBeam1, 0);

		horizontalLaserBeam1 = Sprite::create("LaserBeam.png");
		horizontalLaserBeam1->setPosition(laser1_Pos.x, 87);
		horizontalLaserBeam1->setAnchorPoint(Point(0, 0.5));
		this->addChild(horizontalLaserBeam1, 0);
	}

	else if (TestManager::getInstance()->currentStage == 6)
	{
		laser1 = Sprite::create("Laser.png");
		laser1->setRotation(-90.0f);
		this->addChild(laser1, 1);

		laser1_Pos = Vec2(93, 288);
		laser1->setPosition(laser1_Pos);

		horizontalLaserBeam1 = Sprite::create("LaserBeam.png");
		horizontalLaserBeam1->setPosition(laser1_Pos.x, laser1_Pos.y);
		horizontalLaserBeam1->setAnchorPoint(Point(0, 0.5));
		this->addChild(horizontalLaserBeam1, 0);

		verticalLaserBeam1 = Sprite::create("LaserBeam.png");
		verticalLaserBeam1->setPosition(489, 288);
		verticalLaserBeam1->setAnchorPoint(Point(0.5, 0));
		this->addChild(verticalLaserBeam1, 0);

		laser2 = Sprite::create("Laser.png");
		laser2->setRotation(-90.0f);
		this->addChild(laser2, 1);

		laser2_Pos = Vec2(93, 416);
		laser2->setPosition(laser2_Pos);

		horizontalLaserBeam2 = Sprite::create("LaserBeam.png");
		horizontalLaserBeam2->setPosition(laser2_Pos.x, laser2_Pos.y);
		horizontalLaserBeam2->setAnchorPoint(Point(0, 0.5));
		this->addChild(horizontalLaserBeam2, 0);

		verticalLaserBeam2 = Sprite::create("LaserBeam.png");
		verticalLaserBeam2->setPosition(873, 416);
		verticalLaserBeam2->setAnchorPoint(Point(0.5, 0));
		this->addChild(verticalLaserBeam2, 0);

		laser3 = Sprite::create("Laser.png");
		laser3->setRotation(-90.0f);
		this->addChild(laser3, 1);

		laser3_Pos = Vec2(93, 480);
		laser3->setPosition(laser3_Pos);

		horizontalLaserBeam3 = Sprite::create("LaserBeam.png");
		horizontalLaserBeam3->setPosition(laser3_Pos.x, laser3_Pos.y);
		horizontalLaserBeam3->setAnchorPoint(Point(0, 0.5));
		this->addChild(horizontalLaserBeam3, 0);

		verticalLaserBeam3 = Sprite::create("LaserBeam.png");
		verticalLaserBeam3->setPosition(1129, 480);
		verticalLaserBeam3->setAnchorPoint(Point(0.5, 0));
		this->addChild(verticalLaserBeam3, 0);

		TestManager::getInstance()->_verticalLaser2 = verticalLaserBeam2;
		TestManager::getInstance()->_verticalLaser3 = verticalLaserBeam3;

		TestManager::getInstance()->_horizontalLaser2 = horizontalLaserBeam2;
		TestManager::getInstance()->_horizontalLaser3 = horizontalLaserBeam3;

	}

	TestManager::getInstance()->_verticalLaser1 = verticalLaserBeam1;

	TestManager::getInstance()->_horizontalLaser1 = horizontalLaserBeam1;
	

	/*verticalLaserBeam1		->setPosition(verticalLaserBeam1_Pos);
	verticalLaserBeam2		->setPosition(verticalLaserBeam2_Pos);

	horizontalLaserBeam1	->setPosition(horizontalLaserBeam1_Pos);
	horizontalLaserBeam2	->setPosition(horizontalLaserBeam2_Pos);*/

	this->scheduleUpdate();

	return true;
}

void Laser::update(float _dt)
{
	if (TestManager::getInstance()->currentStage == 4)
	{
		if (TestManager::getInstance()->laser1Reflected == 1)
		{
			verticalLaserBeam1->setScaleY(145.0f);
			if (TestManager::getInstance()->rightDir == 1)
			{
				horizontalLaserBeam1->setScaleX(60.0f);
			}
			else if (TestManager::getInstance()->rightDir == 0)
			{
				horizontalLaserBeam1->setScaleX(-150.0f);
			}
		}
		else if (TestManager::getInstance()->laser1Reflected == 0)
		{
			verticalLaserBeam1->setScaleY(175.0f);
			horizontalLaserBeam1->setScaleX(0.0f);
		}

		if (TestManager::getInstance()->laser2Reflected == 1)
		{
			verticalLaserBeam2->setScaleY(145.0f);
			if (TestManager::getInstance()->rightDir == 1)
			{
				horizontalLaserBeam2->setScaleX(150.0f);
			}
			else if (TestManager::getInstance()->rightDir == 0)
			{
				horizontalLaserBeam2->setScaleX(-60.0f);
			}
		}
		else if (TestManager::getInstance()->laser2Reflected == 0)
		{
			verticalLaserBeam2->setScaleY(175.0f);
			horizontalLaserBeam2->setScaleX(0.0f);
		}
	}

	else if (TestManager::getInstance()->currentStage == 5)
	{
		if (TestManager::getInstance()->laser1Reflected == 1)
		{
			verticalLaserBeam1->setScaleY(210.0f);
			if (TestManager::getInstance()->rightDir == 1)
			{
				if (TestManager::getInstance()->blueOn == 1 && TestManager::getInstance()->greenOn == 1)
				{
					horizontalLaserBeam1->setScaleX(180.0f);
				}
				else if (TestManager::getInstance()->blueOn != 1 || TestManager::getInstance()->greenOn != 1)
				{
					horizontalLaserBeam1->setScaleX(74.5f);
				}
				
			}
			else if (TestManager::getInstance()->rightDir == 0)
			{
				horizontalLaserBeam1->setScaleX(-150.0f);
			}
			
			
		}
		else if (TestManager::getInstance()->laser1Reflected == 0)
		{
			verticalLaserBeam1->setScaleY(250.0f);
			horizontalLaserBeam1->setScaleX(0.0f);
		}
		
	}
	else if (TestManager::getInstance()->currentStage == 6)
	{
		horizontalLaserBeam1->setScaleX(220.0f);
		if (TestManager::getInstance()->laser1Reflected == 1)
		{
			if (TestManager::getInstance()->rightDir == 0)
			{
				verticalLaserBeam1->setScaleY(300.0f);
				horizontalLaserBeam1->setScaleX(120.0f);
			}
			else if (TestManager::getInstance()->rightDir == 1)
			{
				verticalLaserBeam1->setScaleY(0.0f);
				horizontalLaserBeam1->setScaleX(120.0f);
			}
		}
		else if (TestManager::getInstance()->laser1Reflected == 0)
		{
			horizontalLaserBeam1->setScaleX(250.0f);
		}
	}
}