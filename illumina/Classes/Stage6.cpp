#include "TestManager.h"
#include "Stage6.h"
#include "Stage6Tile.h"
#include "Character.h"
#include "RedLight.h"
#include "GreenLight.h"
#include "Laser.h"
#include "Recognizer.h"
#include "Mirrors.h"
#include "Mirror.h"

bool Stage6::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	backSprite = Sprite::create("BackGround/Laboratory1.png");
	backSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(backSprite);

	blockSprite1 = Sprite::create("Stage66/Block1.png");
	blockSprite1->setPosition(480, 224);
	this->addChild(blockSprite1);

	blockSprite2 = Sprite::create("Stage66/Block2.png");
	blockSprite2->setPosition(864, 352);
	this->addChild(blockSprite2);

	tileLayer		= Stage6Tile::create();
	charLayer		= Character::create();
	laserLayer		= Laser::create();
	recognizerLayer = Recognizer::create();
	redLightLayer	= RedLight::create();
	greenLightLayer = GreenLight::create();
	mirrorsLayer	= Mirrors::create();
	TestManager::getInstance()->_boxLayer = nullptr;

	TestManager::getInstance()->_mirrorLayer = mirrorsLayer;


	if (tileLayer == NULL)
	{
		return false;
	}
	this->addChild(tileLayer, 8);

	if (charLayer == NULL)
	{
		return false;
	}
	this->addChild(charLayer, 10);

	if (laserLayer == NULL)
	{
		return false;
	}
	this->addChild(laserLayer, 6);

	if (recognizerLayer == NULL)
	{
		return false;
	}
	this->addChild(recognizerLayer, 7);

	if (redLightLayer == NULL)
	{
		return false;
	}
	this->addChild(redLightLayer, 6);

	if (greenLightLayer == NULL)
	{
		return false;
	}
	this->addChild(greenLightLayer, 6);

	if (mirrorsLayer == NULL)
	{
		return false;
	}
	this->addChild(mirrorsLayer, 9);

	if (!Scene::init())
	{
		return false;
	}

	this->scheduleUpdate();

	(TestManager::getInstance()->_red1)->setBlendFunc(BlendFunc::ADDITIVE);
	(TestManager::getInstance()->_green1)->setBlendFunc(BlendFunc::ADDITIVE);

	CFootHold hold601(Vec2(0, 64), Vec2(0, 800), 601);
	_foothold.InsertTree(hold601);

	CFootHold hold602(Vec2(0, 64), Vec2(128, 64), 602);
	_foothold.InsertTree(hold602);

	CFootHold hold603(Vec2(128, 64), Vec2(128, 128), 603);
	_foothold.InsertTree(hold603);

	CFootHold hold604(Vec2(128, 128), Vec2(320, 128), 604);
	_foothold.InsertTree(hold604);

	CFootHold hold605(Vec2(320, 128), Vec2(320, 192), 605);
	_foothold.InsertTree(hold605);

	CFootHold hold606(Vec2(320, 192), Vec2(512, 192), 606);
	_foothold.InsertTree(hold606);

	CFootHold hold607(Vec2(512, 192), Vec2(512, 256), 607);
	_foothold.InsertTree(hold607);

	CFootHold hold608(Vec2(512, 256), Vec2(704, 256), 608);
	_foothold.InsertTree(hold608);

	CFootHold hold609(Vec2(704, 256), Vec2(704, 320), 609);
	_foothold.InsertTree(hold609);

	CFootHold hold610(Vec2(704, 320), Vec2(896, 320), 610);
	_foothold.InsertTree(hold610);

	CFootHold hold611(Vec2(896, 320), Vec2(896, 384), 611);
	_foothold.InsertTree(hold611);

	CFootHold hold612(Vec2(896, 384), Vec2(1088, 384), 612);
	_foothold.InsertTree(hold612);

	CFootHold hold613(Vec2(1088, 384), Vec2(1088, 448), 613);
	_foothold.InsertTree(hold613);

	CFootHold hold614(Vec2(1088, 448), Vec2(1280, 448), 614);
	_foothold.InsertTree(hold614);

	CFootHold hold615(Vec2(1280, 448), Vec2(1280, 800), 615);
	_foothold.InsertTree(hold615);

	//블럭
	CFootHold hold616(Vec2(448, 192), Vec2(448, 256), 616);
	_foothold.InsertTree(hold616);

	CFootHold hold617(Vec2(448, 256), Vec2(512, 256), 617);
	_foothold.InsertTree(hold617);

	CFootHold hold618(Vec2(832, 320), Vec2(832, 384), 618);
	_foothold.InsertTree(hold618);

	CFootHold hold619(Vec2(832, 384), Vec2(896, 384), 619);
	_foothold.InsertTree(hold619);

	Vector<Node*> mirrors = mirrorsLayer->getChildren();

	int mirrorIndex = 620;

	for (int j = 0; j < mirrors.size(); ++j)
	{
		Mirror* mirror = (Mirror*)mirrors.at(j);

		mirror->Setting(mirrorIndex);
		mirrorIndex++;
	}

	return true;
}

void Stage6::update(float _dt)
{
	Scene* scene = Director::getInstance()->getRunningScene();

	SceneBase* sceneBase = (SceneBase*)scene;  //형변환

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	if (isRedDeleted == false && isRedCreated == true)
	{
		if (TestManager::getInstance()->red1On == 1)
		{
			tree->deleteHoldWithIndex(616);
			tree->deleteHoldWithIndex(617);

			isRedDeleted = true;
			isRedCreated = false;
		}
	}
	/*else if (isRedCreated == false && isRedDeleted == true)
	{
		if (TestManager::getInstance()->red1On != 1)
		{
			CFootHold hold616(Vec2(448, 192), Vec2(448, 256), 616);
			tree->InsertTree(hold616);

			CFootHold hold617(Vec2(448, 256), Vec2(512, 256), 617);
			tree->InsertTree(hold617);

			isRedCreated = true;
			isRedDeleted = false;
		}
	}*/

	if (isGreenDeleted == false && isGreenCreated == true)
	{
		if (TestManager::getInstance()->greenOn == 1)
		{
			tree->deleteHoldWithIndex(618);
			tree->deleteHoldWithIndex(619);

			isGreenDeleted = true;
			isGreenCreated = false;
		}
	}
	/*else if (isGreenCreated == false && isGreenDeleted == true)
	{
		if (TestManager::getInstance()->greenOn != 1)
		{
			CFootHold hold618(Vec2(832, 320), Vec2(832, 384), 618);
			tree->InsertTree(hold618);

			CFootHold hold619(Vec2(832, 384), Vec2(896, 384), 619);
			tree->InsertTree(hold619);

			isGreenCreated = true;
			isGreenDeleted = false;
		}
	}*/

	Rect laserRect1 = TestManager::getInstance()->_horizontalLaser1->getBoundingBox();
	Rect laserRect2 = TestManager::getInstance()->_horizontalLaser2->getBoundingBox();
	Rect laserRect3 = TestManager::getInstance()->_horizontalLaser3->getBoundingBox();

	Rect recognizer1 = TestManager::getInstance()->_recognizer1->getBoundingBox();
	Rect recognizer2 = TestManager::getInstance()->_recognizer2->getBoundingBox();
	Rect recognizer3 = TestManager::getInstance()->_recognizer3->getBoundingBox();

	if (laserRect1.intersectsRect(recognizer1))
	{
		TestManager::getInstance()->_recognizer1->setTexture("RecognizerOn.png");

	}
	else if (laserRect2.intersectsRect(recognizer2))
	{
		TestManager::getInstance()->red1On = 0;
		TestManager::getInstance()->_recognizer2->setTexture("RecognizerOn.png");
	}
	else if (laserRect3.intersectsRect(recognizer3))
	{
		TestManager::getInstance()->greenOn = 0;
		TestManager::getInstance()->_recognizer3->setTexture("RecognizerOn.png");
	}

	if (TestManager::getInstance()->_mirrorLayer != nullptr)
	{
		Vector<Node*>mirrors = TestManager::getInstance()->_mirrorLayer->getChildren();

		for (int i = 0; i < mirrors.size(); ++i)
		{
			Rect mirrorRect = mirrors.at(i)->getBoundingBox();
			{
				if (mirrorRect.intersectsRect(laserRect1) && TestManager::getInstance()->holding == 0)
				{
					TestManager::getInstance()->_currentReflectMirror = (Mirror*)mirrors.at(i);
					TestManager::getInstance()->_currentReflectMirror->setPosition(480, 288);
					TestManager::getInstance()->laser1Reflected = 1;
					break;
				}
				else if (TestManager::getInstance()->holding == 1)
				{
					TestManager::getInstance()->laser1Reflected = 0;
				}

				if (mirrorRect.intersectsRect(laserRect2) && TestManager::getInstance()->holding == 0)
				{
					TestManager::getInstance()->_currentReflectMirror = (Mirror*)mirrors.at(i);
					TestManager::getInstance()->_currentReflectMirror->setPosition(864, 416);
					TestManager::getInstance()->laser2Reflected = 1;
					break;
				}
				else if (TestManager::getInstance()->holding == 1)
				{
					TestManager::getInstance()->laser2Reflected = 0;
				}

				if (mirrorRect.intersectsRect(laserRect3) && TestManager::getInstance()->holding == 0)
				{
					TestManager::getInstance()->_currentReflectMirror = (Mirror*)mirrors.at(i);
					TestManager::getInstance()->_currentReflectMirror->setPosition(1120, 544);
					TestManager::getInstance()->laser3Reflected = 1;
					break;
				}
				else if (TestManager::getInstance()->holding == 1)
				{
					TestManager::getInstance()->laser3Reflected = 0;
				}
			}
		}
	}
}