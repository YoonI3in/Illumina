#pragma once
#include <cocos2d.h>

USING_NS_CC;

class MenuBackGround;
class MenuSelect;

class MenuScene :public Scene
{
protected:	
	MenuBackGround*		menuBG;
	MenuSelect*			menuSelect;
public:
	static Scene* createScene();

	CREATE_FUNC(MenuScene);

	virtual bool init();
};