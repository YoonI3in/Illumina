#include "TestManager.h"
#include "Stage3.h"
#include "Stage3Tile.h"
#include "Stage4.h"
#include "Character.h"
#include "RedLight.h"
#include "Box.h"
#include "Boxes.h"
#include "Button.h"
#include "Buttons.h"

bool Stage3::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	backSprite = Sprite::create("BackGround/Storage.png");
	backSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(backSprite);

	blockSprite = Sprite::create("Stage3/Block.png");
	blockSprite->setPosition(192, 544);
	this->addChild(blockSprite, 0);

	doorSprite = Sprite::create("Door.png");
	doorSprite->setAnchorPoint(Point(0.5, 0));
	doorSprite->setPosition(1264, 66);
	this->addChild(doorSprite);

	tileLayer		= Stage3Tile::create();
	charLayer		= Character::create();
	redLightLayer	= RedLight::create();
	boxesLayer		= Boxes::create();
	buttonsLayer	= Buttons::create();

	TestManager::getInstance()->_boxLayer = boxesLayer;
	TestManager::getInstance()->_buttonLayer = buttonsLayer;

	if (tileLayer == NULL)
	{
		return false;
	}
	this->addChild(tileLayer, 8);

	if (redLightLayer == NULL)
	{
		return false;
	}
	this->addChild(redLightLayer, 7);

	if (buttonsLayer == NULL)
	{
		return false;
	}
	this->addChild(buttonsLayer, 9);

	if (boxesLayer == NULL)
	{
		return false;
	}
	this->addChild(boxesLayer, 9);

	if (charLayer == NULL)
	{
		return false;
	}
	this->addChild(charLayer, 10);

	if (!Scene::init())
	{
		return false;
	}
	this->scheduleUpdate();

	(TestManager::getInstance()->_red1)->setBlendFunc(BlendFunc::ADDITIVE);

	CFootHold hold301(Vec2(0, 512), Vec2(384, 512), 301);
	_foothold.InsertTree(hold301);

	/*CFootHold hold302(Vec2(64, 630), Vec2(64, 830), 302);
	_foothold.InsertTree(hold302);*/

	CFootHold hold303(Vec2(0, 512), Vec2(0, 800), 303);
	_foothold.InsertTree(hold303);

	CFootHold hold304(Vec2(192, 64), Vec2(192, 448), 304);
	_foothold.InsertTree(hold304);

	CFootHold hold305(Vec2(192, 64), Vec2(448, 64), 305);
	_foothold.InsertTree(hold305);

	CFootHold hold306(Vec2(448, 64), Vec2(448, 128), 306);
	_foothold.InsertTree(hold306);

	CFootHold hold307(Vec2(448, 128), Vec2(768, 128), 307);
	_foothold.InsertTree(hold307);

	CFootHold hold308(Vec2(768, 64), Vec2(768, 128), 308);
	_foothold.InsertTree(hold308);

	CFootHold hold309(Vec2(768, 64), Vec2(1280, 64), 309);
	_foothold.InsertTree(hold309);

	CFootHold hold310(Vec2(1248, 64), Vec2(1248, 192), 310);//문
	_foothold.InsertTree(hold310);

	CFootHold hold311(Vec2(896, 256), Vec2(1088, 256), 311);
	_foothold.InsertTree(hold311);

	CFootHold hold312(Vec2(1088, 256), Vec2(1088, 800), 312);
	_foothold.InsertTree(hold312);

	CFootHold hold313(Vec2(448, 384), Vec2(768, 384), 313);
	_foothold.InsertTree(hold313);

	//블럭
	CFootHold hold314(Vec2(95, 510), Vec2(95, 573), 314);
	_foothold.InsertTree(hold314);

	CFootHold hold315(Vec2(95, 573), Vec2(287, 573), 315);
	_foothold.InsertTree(hold315);

	CFootHold hold316(Vec2(287, 510), Vec2(287, 573), 316);
	_foothold.InsertTree(hold316);

	Vector<Node*> boxes = boxesLayer->getChildren();

	int boxIndex = 317;

	for (int i = 0; i < boxes.size(); ++i)
	{
		Box* box = (Box*)boxes.at(i);

		box->Setting(boxIndex);
		boxIndex++;
	}

	Vector<Node*> buttons = buttonsLayer->getChildren();

	for (int j = 0; j < buttons.size(); ++j)
	{
		Button* button = (Button*)buttons.at(j);

		button->Setting(buttonIndex);
		buttonIndex++;
	}

	return true;
}


void Stage3::update(float _dt)
{
	Scene* scene = Director::getInstance()->getRunningScene();

	SceneBase* sceneBase = (SceneBase*)scene;  //형변환

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	if (isDeleted == false && isCreated == true)
	{
		if (TestManager::getInstance()->red1On == 1)
		{
			tree->deleteHoldWithIndex(314);
			tree->deleteHoldWithIndex(315);
			tree->deleteHoldWithIndex(316);

			isDeleted = true;
			isCreated = false;
		}
	}

	else if (isCreated == false && isDeleted == true)
	{
		if (TestManager::getInstance()->red1On != 1)
		{
			CFootHold hold314(Vec2(128, 512), Vec2(128, 576), 314);
			tree->InsertTree(hold314);

			CFootHold hold315(Vec2(128, 576), Vec2(256, 576), 315);
			tree->InsertTree(hold315);

			CFootHold hold316(Vec2(256, 512), Vec2(256, 576), 316);
			tree->InsertTree(hold316);

			isCreated = true;
			isDeleted = false;
		}
	}

	auto char_Rect = charLayer->BoundingBox();
	Rect nextStage = Rect(1278, 64, 2, 128);

	if (char_Rect.intersectsRect(nextStage))
	{
		changeScene();
	}

	if (TestManager::getInstance()->_boxLayer != nullptr)
	{
		Vector<Node*> boxes = TestManager::getInstance()->_boxLayer->getChildren();

		for (int i = 0; i < boxes.size(); ++i)
		{
			Rect boxRect = boxes.at(i)->getBoundingBox();

			Vector<Node*> buttons = TestManager::getInstance()->_buttonLayer->getChildren();

			for (int j = 0; j < buttons.size(); j++)
			{
				Rect buttonRect1 = buttons.at(0)->getBoundingBox();
				Rect buttonRect2 = buttons.at(1)->getBoundingBox();

				if (boxRect.intersectsRect(buttonRect1))
				{
					TestManager::getInstance()->_currentPressedButton = (Button*)buttons.at(0);
					TestManager::getInstance()->_currentPressedButton->DeleteFootHold();
					TestManager::getInstance()->_currentPressedButton->PressedSetting(buttonIndex);
					doorSprite->setVisible(false);
					tree->deleteHoldWithIndex(310);
					break;
				}
				else if (boxRect.intersectsRect(buttonRect2))
				{
					TestManager::getInstance()->_currentPressedButton = (Button*)buttons.at(1);
					TestManager::getInstance()->_currentPressedButton->DeleteFootHold();
					TestManager::getInstance()->_currentPressedButton->PressedSetting(buttonIndex);
					TestManager::getInstance()->red1On = 1;
					break;
				}
				
			}
		}
	}
}

void Stage3::changeScene()
{
	TestManager::getInstance()->currentStage++;
	TestManager::getInstance()->pick = 0;
	Director::getInstance()->replaceScene(Stage4::create());
}