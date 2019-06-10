#include "TestManager.h"
#include "MenuSelect.h"
#include "Stage1.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

bool MenuSelect::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	colorchage = &change_Num;

	WideCharToMultiByte(CP_UTF8, 0, L"Start", -1, start, 10, NULL, NULL);
	select1	= Label::createWithTTF(start, "fonts/verdana.ttf", 120);
	if (select1 == NULL)
	{
		return false;
	}
	select1_Pos = Vec2(visibleSize.width/2, 300);
	select1->setPosition(select1_Pos);
	this->addChild(select1, 3);

	/*WideCharToMultiByte(CP_UTF8, 0, L"Option", -1, option, 10, NULL, NULL);
	select2	= Label::createWithTTF(option, "fonts/ExtraSprinkles.ttf", 80);
	if (select2 == NULL)
	{
		return false;
	}
	select2_Pos = Vec2(visibleSize.width / 2, 250);
	select2->setPosition(select2_Pos);
	this->addChild(select2, 3);*/

	WideCharToMultiByte(CP_UTF8, 0, L"Exit", -1, exit, 10, NULL, NULL);
	select3	= Label::createWithTTF(exit, "fonts/verdana.ttf", 120);
	if (select3 == NULL)
	{
		return false;
	}
	select3_Pos = Vec2(visibleSize.width / 2, 150);
	select3->setPosition(select3_Pos);
	this->addChild(select3, 3);

	this->scheduleUpdate();

	auto text_Keylistener = EventListenerKeyboard::create();

	text_Keylistener->onKeyPressed  = CC_CALLBACK_2(MenuSelect::onKeyPressed, this);
	 
	text_Keylistener->onKeyReleased = CC_CALLBACK_2(MenuSelect::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(text_Keylistener, this);

	change_Index();

	return true;
}

void MenuSelect::change_Index()
{
	select1->setColor(Color3B(0, 0, 0));
	//select2->setColor(Color3B(255, 255, 255));
	select3->setColor(Color3B(0, 0, 0));

	if (change_Num == 1)
	{
		select1->setColor(Color3B(0, 255, 0));
	}
	/*else if (change_Num == 0)
	{
		select2->setColor(Color3B(255, 255, 150));
	}*/
	else if (change_Num == 0)
	{
		select3->setColor(Color3B(0, 255, 0));
	}
}

void MenuSelect::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
	}
}

void MenuSelect::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		if (change_Num + 1 <= 1)
		{
			change_Num++;

			change_Index();
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		if (change_Num - 1 >= 0)
		{
			change_Num--;

			change_Index();
		}
	}
	if (change_Num == 1 && keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		TestManager::getInstance()->currentStage++;

		auto scene = Stage1::create();
		SimpleAudioEngine::getInstance()->playBackgroundMusic("mus_stage.mp3", true);
		Director::getInstance()->replaceScene(scene);
	}
	else if (change_Num == 0 && keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		Director::getInstance()->end();
	}

}