#include "TestManager.h"
#include "Stage4.h"
#include "Stage4Tile.h"
#include "Stage5.h"
#include "Character.h"
#include "Laser.h"
#include "Recognizer.h"
#include "RedLight.h"
#include "Mirrors.h"
#include "Mirror.h"

bool Stage4::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	backSprite = Sprite::create("BackGround/Laboratory1.png");
	backSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(backSprite);

	doorSprite = Sprite::create("Door.png");
	doorSprite->setAnchorPoint(Point(0.5, 0));
	doorSprite->setPosition(1264, 66);
	doorSprite->setVisible(true);
	this->addChild(doorSprite);

	tileLayer		= Stage4Tile::create();
	charLayer		= Character::create();
	laserLayer		= Laser::create();
	recognizerLayer = Recognizer::create();
	redLightLayer	= RedLight::create();
	mirrorsLayer	= Mirrors::create();

	TestManager::getInstance()->_mirrorLayer = mirrorsLayer;
	TestManager::getInstance()->_boxLayer = nullptr;

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

	if (mirrorsLayer == NULL)
	{
		return false;
	}
	this->addChild(mirrorsLayer, 9);

	if (!Scene::init())
	{
		return false;
	}

	(TestManager::getInstance()->_red1)->setBlendFunc(BlendFunc::ADDITIVE);

	this->scheduleUpdate();

	CFootHold hold401(Vec2(0, 64), Vec2(0, 200), 401);
	_foothold.InsertTree(hold401);

	CFootHold hold402(Vec2(0, 64), Vec2(192, 64), 402);
	_foothold.InsertTree(hold402);

	CFootHold hold403(Vec2(192, 64), Vec2(192, 128), 403);
	_foothold.InsertTree(hold403);

	CFootHold hold404(Vec2(192, 128), Vec2(256, 128), 404);
	_foothold.InsertTree(hold404);

	CFootHold hold405(Vec2(256, 128), Vec2(256, 192), 405);
	_foothold.InsertTree(hold405);

	CFootHold hold406(Vec2(256, 192), Vec2(320, 192), 406);
	_foothold.InsertTree(hold406);

	CFootHold hold407(Vec2(320, 192), Vec2(320, 256), 407);
	_foothold.InsertTree(hold407);

	CFootHold hold408(Vec2(320, 256), Vec2(608, 256), 408);
	_foothold.InsertTree(hold408);

	CFootHold hold409(Vec2(608, 256), Vec2(608, 320), 409);
	_foothold.InsertTree(hold409);

	CFootHold hold410(Vec2(608, 320), Vec2(672, 320), 410);
	_foothold.InsertTree(hold410);

	CFootHold hold411(Vec2(672, 256), Vec2(672, 320), 411);
	_foothold.InsertTree(hold411);

	CFootHold hold412(Vec2(672, 256), Vec2(960, 256), 412);
	_foothold.InsertTree(hold412);

	CFootHold hold413(Vec2(960, 192), Vec2(960, 256), 413);
	_foothold.InsertTree(hold413);

	CFootHold hold414(Vec2(960, 192), Vec2(1024, 192), 414);
	_foothold.InsertTree(hold414);

	CFootHold hold415(Vec2(1024, 128), Vec2(1024, 192), 415);
	_foothold.InsertTree(hold415);

	CFootHold hold416(Vec2(1024, 128), Vec2(1088, 128), 416);
	_foothold.InsertTree(hold416);

	CFootHold hold417(Vec2(1088, 64), Vec2(1088, 128), 417);
	_foothold.InsertTree(hold417);

	CFootHold hold418(Vec2(1088, 64), Vec2(1280, 64), 418);
	_foothold.InsertTree(hold418);

	CFootHold hold419(Vec2(1280, 64), Vec2(1280, 300), 419);
	_foothold.InsertTree(hold419);

	CFootHold hold420(Vec2(1248, 64), Vec2(1248, 300), 420);//문
	_foothold.InsertTree(hold420);

	Vector<Node*> mirrors = mirrorsLayer->getChildren();

	int tempIndex = 421;

	for (int i = 0; i < mirrors.size(); ++i)
	{
		Mirror* mirror = (Mirror*)mirrors.at(i);

		mirror->Setting(tempIndex);
		tempIndex++;
	}

	return true;
}

void Stage4::update(float _dt)
{

	Scene* scene = Director::getInstance()->getRunningScene();

	SceneBase* sceneBase = (SceneBase*)scene;  //형변환

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	auto char_Rect = charLayer->BoundingBox();
	Rect nextStage = Rect(1278, 64, 2, 128);

	if (char_Rect.intersectsRect(nextStage))
	{
		changeScene();
	}

	Rect vLaser1Rect = TestManager::getInstance()->_verticalLaser1->getBoundingBox();
	Rect vLaser2Rect = TestManager::getInstance()->_verticalLaser2->getBoundingBox();

	Rect hLaser1Rect = TestManager::getInstance()->_horizontalLaser1->getBoundingBox();
	Rect hLaser2Rect = TestManager::getInstance()->_horizontalLaser2->getBoundingBox();

	Rect recognizer1 = TestManager::getInstance()->_recognizer1->getBoundingBox();
	Rect recognizer2 = TestManager::getInstance()->_recognizer2->getBoundingBox();

	if (hLaser1Rect.intersectsRect(recognizer1))
	{
		TestManager::getInstance()->_recognizer1->setTexture("RecognizerOn.png");
		TestManager::getInstance()->_red1->setVisible(true);
	}
	else if (hLaser2Rect.intersectsRect(recognizer2))
	{
		TestManager::getInstance()->_recognizer2->setTexture("RecognizerOn.png");
		doorSprite->setVisible(false);
		tree->deleteHoldWithIndex(420);
	}

	if (TestManager::getInstance()->_mirrorLayer != nullptr)
	{
		Vector<Node*> mirrors = TestManager::getInstance()->_mirrorLayer->getChildren();

		for (int i = 0; i < mirrors.size(); ++i)
		{
			Rect mirrorRect = mirrors.at(i)->getBoundingBox();
			{
				if (mirrorRect.intersectsRect(vLaser1Rect) && TestManager::getInstance()->holding == 0)
				{
					TestManager::getInstance()->_currentReflectMirror = (Mirror*)mirrors.at(i);
					TestManager::getInstance()->_currentReflectMirror->setPosition(416, 286);
					TestManager::getInstance()->laser1Reflected = 1;
					break;
				}
				else if (mirrorRect.intersectsRect(vLaser1Rect) == false || TestManager::getInstance()->holding == 1)
				{
					TestManager::getInstance()->laser1Reflected = 0;
				}
			}
			{
				if (mirrorRect.intersectsRect(vLaser2Rect) && TestManager::getInstance()->holding == 0)
				{
					TestManager::getInstance()->_currentReflectMirror = (Mirror*)mirrors.at(i);
					TestManager::getInstance()->_currentReflectMirror->setPosition(864, 286);
					TestManager::getInstance()->laser2Reflected = 1;
					break;
				}
				else if (TestManager::getInstance()->holding == 1)
				{
					TestManager::getInstance()->laser2Reflected = 0;
				}
			}
		}
	}
}

void Stage4::changeScene()
{
	TestManager::getInstance()->blueOn = 1;
	TestManager::getInstance()->greenOn = 0;
	TestManager::getInstance()->laser1Reflected = 0;
	TestManager::getInstance()->currentStage++;
	Director::getInstance()->replaceScene(Stage5::create());
}