#include "Button.h"
#include "TestManager.h"
#include "SceneBase.h"

bool Button::init()
{
	initWithFile("Object/UnPressedButton.png");

	scheduleUpdate();

	return true;
}

void Button::Setting(int index)
{
	buttonIndex = index;
	SceneBase* sceneBase = (SceneBase*)this->getParent()->getParent();
	CFootHoldTree* tree = sceneBase->GetFootHoldTree();
	auto button_Rect = getBoundingBox();

	Vec2 buttonLeftTop(button_Rect.origin.x, button_Rect.origin.y + button_Rect.size.height);
	Vec2 buttonRightTop(button_Rect.origin.x + button_Rect.size.width, button_Rect.origin.y + button_Rect.size.height);
	CFootHold hold(buttonLeftTop, buttonRightTop, index);
	tree->InsertTree(hold);
}

void Button::PressedSetting(int index)
{
	buttonIndex = index;
	SceneBase* sceneBase = (SceneBase*)this->getParent()->getParent();
	CFootHoldTree* tree = sceneBase->GetFootHoldTree();
	auto button_Rect = getBoundingBox();

	Vec2 pressedButtonLeftTop(button_Rect.origin.x+1, button_Rect.origin.y + button_Rect.size.height-6);
	Vec2 pressedButtonRightTop(button_Rect.origin.x + button_Rect.size.width-1, button_Rect.origin.y + button_Rect.size.height-6);
	CFootHold hold(pressedButtonLeftTop, pressedButtonRightTop, index);
	tree->InsertTree(hold);
}

void Button::DeleteFootHold()
{
	SceneBase* sceneBase = (SceneBase*)this->getParent()->getParent();

	CFootHoldTree* tree = sceneBase->GetFootHoldTree();

	tree->deleteHoldWithIndex(buttonIndex);
}

void Button::update(float _dt)
{
	
}