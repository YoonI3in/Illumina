#include "TestManager.h"
#include "Stage2.h"
#include "Stage2Tile.h"
#include "Stage3.h"
#include "Character.h"
#include "RedLight.h"
#include "Box.h"
#include "Boxes.h"
#include "Button.h"
#include "Buttons.h"

bool Stage2::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	backSprite = Sprite::create("BackGround/Storage.png");
	backSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(backSprite);

	blockSprite = Sprite::create("Stage2/Block.png");
	blockSprite->setAnchorPoint(Point(0.5, 0));
	blockSprite->setPosition(1120, 0);
	this->addChild(blockSprite);

	charLayer			= Character		::create();
	tileLayer			= Stage2Tile	::create();
	//doorSprite			= Door			::create();
	redLightLayer		= RedLight		::create();
	boxesLayer			= Boxes			::create();
	buttonsLayer		= Buttons		::create();
	
	TestManager::getInstance()->_boxLayer = boxesLayer;
	TestManager::getInstance()->_buttonLayer = buttonsLayer;

	if (charLayer == NULL)
	{
		return false;
	}
	this->addChild(charLayer, 10);

	if (tileLayer == NULL)
	{
		return false;
	}
	this->addChild(tileLayer, 8);

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

	if (redLightLayer == NULL)
	{
		return false;
	}
	this->addChild(redLightLayer,7);

	if (!Scene::init())
	{
		return false;
	}
	/*this->addChild(TestManager::getInstance()->_boxSprite, TestManager::getInstance()->zNum);
	TestManager::getInstance()->_boxSprite->scheduleUpdate();*/
	
	(TestManager::getInstance()->_red1)->setBlendFunc(BlendFunc::ADDITIVE);


	this->scheduleUpdate();

	//베이스 발판
	CFootHold hold200(Vec2(0, 64), Vec2(1088, 64), 200);
	_foothold.InsertTree(hold200);

	CFootHold hold201(Vec2(1088, 0), Vec2(1088, 64), 201);
	_foothold.InsertTree(hold201);

	CFootHold hold202(Vec2(1152, 0), Vec2(1152, 512), 202);
	_foothold.InsertTree(hold202);

	CFootHold hold203(Vec2(1152, 512), Vec2(1280, 512), 203);
	_foothold.InsertTree(hold203);

	CFootHold hold204(Vec2(1280, 512), Vec2(1280, 640), 204);
	_foothold.InsertTree(hold204);

	//블럭
	CFootHold hold205(Vec2(1088, 62), Vec2(1088, 448), 205);
	_foothold.InsertTree(hold205);

	CFootHold hold206(Vec2(1088, 448), Vec2(1152, 448), 206);
	_foothold.InsertTree(hold206);

	Vector<Node*> boxes = boxesLayer->getChildren();

	int boxIndex = 207;

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

void Stage2::update(float _dt)
{
	Scene* scene = Director::getInstance()->getRunningScene();

	SceneBase* sceneBase = (SceneBase*)scene;  //형변환

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	if (isDeleted == false && isCreated == true)
	{
		if (TestManager::getInstance()->red1On == 1)
		{
			tree->deleteHoldWithIndex(205);
			tree->deleteHoldWithIndex(206);

			isDeleted = true;
			isCreated = false;
		}
	}

	else if (isCreated == false && isDeleted == true)
	{
		if (TestManager::getInstance()->red1On != 1)
		{
			CFootHold hold205(Vec2(1088, 62), Vec2(1088, 448), 205);
			tree->InsertTree(hold205);

			CFootHold hold206(Vec2(1088, 448), Vec2(1152, 448), 206);
			tree->InsertTree(hold206);

			isCreated = true;
			isDeleted = false;
		}
	}

	auto char_Rect = charLayer->BoundingBox();
	Rect nextStage = Rect(1277, 512, 3, 128);

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
				Rect buttonRect = buttons.at(j)->getBoundingBox();

				if (boxRect.intersectsRect(buttonRect))
				{
					TestManager::getInstance()->_currentPressedButton = (Button*)buttons.at(j);
					TestManager::getInstance()->_currentPressedButton->DeleteFootHold();
					TestManager::getInstance()->_currentPressedButton->PressedSetting(buttonIndex);
					TestManager::getInstance()->red1On = 0;
					break;
				}
			}
		}
	}
}

void Stage2::changeScene()
{
	TestManager::getInstance()->currentStage++;
	TestManager::getInstance()->red1On = 0;
	Director::getInstance()->replaceScene(Stage3::create());
}
