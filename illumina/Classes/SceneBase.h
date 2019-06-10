#pragma once

#include <cocos2d.h>
#include "FootHold.h"

USING_NS_CC;

class SceneBase :public Scene
{
public:

	CFootHoldTree* GetFootHoldTree();

	CFootHoldTree _foothold;
};