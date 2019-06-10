#include "TestManager.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Character.h"
#include "Boxes.h"
#include "Box.h"
#include "RedLight.h"

bool Stage1::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	backSprite = Sprite::create("Stage1/Stage1.png");
	backSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(backSprite);

	blockSprite = Sprite::create("Stage1/Block.png");
	blockSprite->setAnchorPoint(Point(0.5, 0));
	blockSprite->setPosition(990, 65);
	this->addChild(blockSprite);

	charLayer			= Character			::create();
	boxesLayer			= Boxes				::create();
	redLightLayer		= RedLight			::create();

	TestManager::getInstance()->_boxLayer = boxesLayer;

	if (charLayer == NULL)
	{
		return false;
	}
	this->addChild(charLayer, 10);

	if(boxesLayer == NULL)
	{
		return false;
	}
	this->addChild(boxesLayer, 9);

	if (redLightLayer == NULL)
	{
		return false;
	}
	this->addChild(redLightLayer, 7);

	if (!Scene::init())
	{
		return false;
	}

	(TestManager::getInstance()->_red1)->setBlendFunc(BlendFunc::ADDITIVE);

	this->scheduleUpdate();

	CFootHold hold100(Vec2(1215, 192), Vec2(1215, 710), 100);
	_foothold.InsertTree(hold100);

	CFootHold hold101(Vec2(63, 64), Vec2(63, 704), 101);
	_foothold.InsertTree(hold101);

	CFootHold hold102(Vec2(63, 64), Vec2(255, 64), 102);
	_foothold.InsertTree(hold102);

	CFootHold hold103(Vec2(255, 64), Vec2(255, 128), 103);
	_foothold.InsertTree(hold103);

	CFootHold hold104(Vec2(255, 128), Vec2(320, 128), 104);
	_foothold.InsertTree(hold104);

	CFootHold hold105(Vec2(320, 128), Vec2(320, 192), 105);
	_foothold.InsertTree(hold105);

	CFootHold hold106(Vec2(320, 192), Vec2(383, 192), 106);
	_foothold.InsertTree(hold106);

	CFootHold hold107(Vec2(383, 64), Vec2(383, 192), 107);
	_foothold.InsertTree(hold107);

	CFootHold hold108(Vec2(383, 64), Vec2(640, 64), 108);
	_foothold.InsertTree(hold108);

	CFootHold hold109(Vec2(640, 64), Vec2(640, 192), 109);
	_foothold.InsertTree(hold109);

	CFootHold hold110(Vec2(640, 192), Vec2(703, 192), 110);
	_foothold.InsertTree(hold110);

	CFootHold hold111(Vec2(703, 64), Vec2(703, 192), 111);
	_foothold.InsertTree(hold111);

	CFootHold hold112(Vec2(709, 64), Vec2(1248, 64), 112);
	_foothold.InsertTree(hold112);

	/*CFootHold hold113(Vec2(1248, 65), Vec2(1248, 192), 113);
	_foothold.InsertTree(hold113);*/

	CFootHold hold114(Vec2(959, 64), Vec2(959, 192), 114);
	_foothold.InsertTree(hold114);

	CFootHold hold115(Vec2(959, 192), Vec2(1021, 192), 115);
	_foothold.InsertTree(hold115);

	CFootHold hold116(Vec2(1021, 64), Vec2(1021, 192), 116);
	_foothold.InsertTree(hold116);

	CFootHold hold117(Vec2(1280, 64), Vec2(1280, 192), 117);
	_foothold.InsertTree(hold117);

	
	/*CFootHold hold118(Vec2(384, 128), Vec2(448, 128), 118);
	_foothold.InsertTree(hold118);*/

	Vector<Node*> boxes = boxesLayer->getChildren();

	int tempIndex = 118;

	for (int i = 0; i < boxes.size(); ++i)
	{
		Box* box = (Box*)boxes.at(i);

		box->Setting(tempIndex);
		tempIndex++;
	}


	return true;
}

Stage1::~Stage1()
{
}

void Stage1::update(float _dt)
{
	Scene* scene = Director::getInstance()->getRunningScene();

	SceneBase* sceneBase = (SceneBase*)scene;  //Çüº¯È¯

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	if(isDeleted == false && isCreated == true)
	{
		if (TestManager::getInstance()->red1On == 1)
		{
			tree->deleteHoldWithIndex(114);
			tree->deleteHoldWithIndex(115);
			tree->deleteHoldWithIndex(116);

			isDeleted = true;
			isCreated = false;
		}
	}
	else if (isCreated == false && isDeleted == true)
	{
		CFootHold hold114(Vec2(959, 65), Vec2(959, 192), 114);
		tree->InsertTree(hold114);

		CFootHold hold115(Vec2(959, 192), Vec2(1021, 192), 115);
		tree->InsertTree(hold115);

		CFootHold hold116(Vec2(1021, 65), Vec2(1021, 192), 116);
		tree->InsertTree(hold116);

		isCreated = true;
		isDeleted = false;
	}

	auto char_Rect = charLayer->BoundingBox();
	Rect nextStage = Rect(1278, 64, 2, 128);

	if (char_Rect.intersectsRect(nextStage))
	{
		//TestManager::getInstance()->redOn = 1;
		changeScene();
	}
}

void Stage1::changeScene()
{
	TestManager::getInstance()->currentStage++;
	TestManager::getInstance()->red1On = 1;
	TestManager::getInstance()->pick = 0;
	Director::getInstance()->replaceScene(Stage2::create());
}