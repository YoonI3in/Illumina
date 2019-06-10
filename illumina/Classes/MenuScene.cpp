#include "MenuScene.h"
#include "MenuBackGround.h"
#include "MenuSelect.h"

Scene* MenuScene::createScene()
{
	auto menuScene = Scene::create();

	menuScene->addChild(menuScene);

	return menuScene;
}

bool MenuScene::init()
{
	menuBG			= MenuBackGround::create();
	menuSelect		= MenuSelect::create();

	if (menuBG == NULL)
	{
		return false;
	}
	this->addChild(menuBG);

	if (menuSelect == NULL)
	{
		return false;
	}
	this->addChild(menuSelect);

	if (!Scene::init())
	{
		return false;
	}
	this->scheduleUpdate();

	return true;
}