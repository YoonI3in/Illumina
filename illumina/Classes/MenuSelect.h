#pragma once
#include <cocos2d.h>

USING_NS_CC;

class MenuSelect :public Layer
{
protected:
	Label*		select1;
	Vec2		select1_Pos;
	char		start[10];

	/*Label*		select2;
	Vec2		select2_Pos;
	char		option[10];*/

	Label*		select3;
	Vec2		select3_Pos;
	char		exit[10];

	int			t_Key;
	int*		colorchage;
	int			change_Num = 1;
public:	
	CREATE_FUNC(MenuSelect);

	virtual bool init();

	virtual void change_Index();

	virtual void onKeyPressed	(EventKeyboard::KeyCode, Event* Code);

	virtual void onKeyReleased	(EventKeyboard::KeyCode, Event* Code);
};