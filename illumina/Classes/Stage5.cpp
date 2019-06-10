#include "TestManager.h"
#include "Stage5.h"
#include "Stage5Tile.h"
#include "Stage6.h"
#include "Character.h"
#include "Laser.h"
#include "Recognizer.h"
#include "BlueLight.h"
#include "GreenLight.h"
#include "Mirrors.h"
#include "Mirror.h"
#include "Boxes.h"
#include "Box.h"

bool Stage5::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	backSprite = Sprite::create("BackGround/Laboratory1.png");
	backSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(backSprite);

	doorSprite = Sprite::create("Door.png");
	doorSprite->setAnchorPoint(Point(0.5, 0));
	doorSprite->setPosition(1264, 65);
	this->addChild(doorSprite);

	blockSprite = Sprite::create("Stage5/Block.png");
	blockSprite->setAnchorPoint(Point(0.5, 0));
	blockSprite->setPosition(352, 64);
	this->addChild(blockSprite);

	tileLayer			= Stage5Tile::create();
	charLayer			= Character::create();
	laserLayer			= Laser::create();
	recognizerLayer		= Recognizer::create();
	blueLightLayer		= BlueLight::create();
	greenLightLayer		= GreenLight::create();
	mirrorsLayer		= Mirrors::create();
	boxesLayer			= Boxes::create();

	TestManager::getInstance()->_mirrorLayer = mirrorsLayer;
	TestManager::getInstance()->_boxLayer	 = boxesLayer;

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

	if (blueLightLayer == NULL)
	{
		return false;
	}
	this->addChild(blueLightLayer, 6);

	if (greenLightLayer == NULL)
	{
		return false;
	}
	this->addChild(greenLightLayer, 6);

	if (boxesLayer == NULL)
	{
		return false;
	}
	this->addChild(boxesLayer, 9);

	if (mirrorsLayer == NULL)
	{
		return false;
	}
	this->addChild(mirrorsLayer, 9);

	if (!Scene::init())
	{
		return false;
	}

	(TestManager::getInstance()->_blue1)->setBlendFunc(BlendFunc::ADDITIVE);
	(TestManager::getInstance()->_green1)->setBlendFunc(BlendFunc::ADDITIVE);

	this->scheduleUpdate();

	CFootHold hold500(Vec2(1088, 256), Vec2(1088, 320), 500);
	_foothold.InsertTree(hold500);

	CFootHold hold501(Vec2(0, 64), Vec2(0, 192), 501);
	_foothold.InsertTree(hold501);

	CFootHold hold502(Vec2(0, 64), Vec2(640, 64), 502);
	_foothold.InsertTree(hold502);

	CFootHold hold503(Vec2(640, 64), Vec2(640, 128), 503);
	_foothold.InsertTree(hold503);

	CFootHold hold504(Vec2(640, 128), Vec2(704, 128), 504);
	_foothold.InsertTree(hold504);

	CFootHold hold505(Vec2(704, 64), Vec2(704, 128), 505);
	_foothold.InsertTree(hold505);

	CFootHold hold506(Vec2(704, 64), Vec2(1280, 64), 506);
	_foothold.InsertTree(hold506);

	CFootHold hold507(Vec2(1248, 62), Vec2(1248, 300), 507);//문
	_foothold.InsertTree(hold507);

	CFootHold hold508(Vec2(960, 256), Vec2(1088,256), 508);
	_foothold.InsertTree(hold508);

	CFootHold hold509(Vec2(1088, 320), Vec2(1216, 320), 509);
	_foothold.InsertTree(hold509);

	CFootHold hold510(Vec2(1216, 320), Vec2(1216, 800), 510);
	_foothold.InsertTree(hold510);

	CFootHold hold599(Vec2(1280, 64), Vec2(1280, 300), 599);
	_foothold.InsertTree(hold599);

	//블럭
	CFootHold hold511(Vec2(320, 63), Vec2(320, 127), 511);
	_foothold.InsertTree(hold511);

	CFootHold hold512(Vec2(320, 127), Vec2(384, 127), 512);
	_foothold.InsertTree(hold512);

	CFootHold hold513(Vec2(384, 63), Vec2(384, 127), 513);
	_foothold.InsertTree(hold513);

	Vector<Node*> boxes = boxesLayer->getChildren();

	int boxIndex = 515;

	for (int i = 0; i < boxes.size(); ++i)
	{
		Box* box = (Box*)boxes.at(i);

		box->Setting(boxIndex);
		boxIndex++;
	}

	Vector<Node*> mirrors = mirrorsLayer->getChildren();

	int mirrorIndex = 550;

	for (int j = 0; j < mirrors.size(); ++j)
	{
		Mirror* mirror = (Mirror*)mirrors.at(j);

		mirror->Setting(mirrorIndex);
		mirrorIndex++;
	}

	return true;
}

void Stage5::update(float _dt)
{
	Scene* scene = Director::getInstance()->getRunningScene();

	SceneBase* sceneBase = (SceneBase*)scene;  //형변환

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	if (isDeleted == false && isCreated == true)
	{
		if (TestManager::getInstance()->blueOn == 1 && TestManager::getInstance()->greenOn == 1)
		{
			tree->deleteHoldWithIndex(511);
			tree->deleteHoldWithIndex(512);
			tree->deleteHoldWithIndex(513);

			isDeleted = true;
			isCreated = false;
		}
	}

	else if (isCreated == false && isDeleted == true)
	{
		if (TestManager::getInstance()->blueOn != 1 || TestManager::getInstance()->greenOn != 1)
		{
			CFootHold hold511(Vec2(320, 63), Vec2(320, 127), 511);
			tree->InsertTree(hold511);

			CFootHold hold512(Vec2(320, 127), Vec2(384, 127), 512);
			tree->InsertTree(hold512);

			CFootHold hold513(Vec2(384, 63), Vec2(384, 127), 513);
			tree->InsertTree(hold513);

			isCreated = true;
			isDeleted = false;
		}
	}

	auto char_Rect = charLayer->BoundingBox();
	Rect nextStage = Rect(1278, 64, 2, 128);

	if (char_Rect.intersectsRect(nextStage))
	{
		//changeScene();
	}

	Rect laserRect = TestManager::getInstance()->_horizontalLaser1->getBoundingBox();

	Rect recognizer = TestManager::getInstance()->_recognizer1->getBoundingBox();

	if (laserRect.intersectsRect(recognizer))
	{
		TestManager::getInstance()->_recognizer1->setTexture("RecognizerOn.png");
		doorSprite->setVisible(false);
		tree->deleteHoldWithIndex(507);
	}

	if (TestManager::getInstance()->_mirrorLayer != nullptr)
	{
		Vector<Node*>mirrors = TestManager::getInstance()->_mirrorLayer->getChildren();

		for (int i = 0; i < mirrors.size(); ++i)
		{
			Rect mirrorRect = mirrors.at(i)->getBoundingBox();
			{
				if (mirrorRect.intersectsRect(laserRect) && TestManager::getInstance()->holding == 0)
				{
					TestManager::getInstance()->_currentReflectMirror = (Mirror*)mirrors.at(i);
					TestManager::getInstance()->_currentReflectMirror->setPosition(96, 94);
					TestManager::getInstance()->laser1Reflected = 1;
					break;
				}
				else if (TestManager::getInstance()->holding == 1)
				{
					TestManager::getInstance()->laser1Reflected = 0;
				}
			}
		}
	}
}

void Stage5::changeScene()
{
	TestManager::getInstance()->currentStage++;
	TestManager::getInstance()->red1On = 1;
	TestManager::getInstance()->greenOn = 1;
	Director::getInstance()->replaceScene(Stage6::create());
}