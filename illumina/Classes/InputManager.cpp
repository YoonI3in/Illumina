//
//  InputManager.cpp
//  Sample
//
//  Created by aheanuri on 2016. 7. 13..
//
//

#include "InputManager.h"

void InputManager::Initialize()
{
    auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    
    if ( _keyboardListener )
    {
        dispatcher->removeEventListener(_keyboardListener);
        _keyboardListener = nullptr;
    }
    
    _keyboardListener = cocos2d::EventListenerKeyboard::create();
    
    _keyboardListener->onKeyPressed = CC_CALLBACK_2(InputManager::onKeyPressed, this);
    _keyboardListener->onKeyReleased = CC_CALLBACK_2(InputManager::onKeyReleased, this);
        
    dispatcher->addEventListenerWithFixedPriority(_keyboardListener, -1);
    
    Reset();
    
    _initialized = true;
}

void InputManager::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    _key[(int)keyCode] = true;
}

void InputManager::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    _key[(int)keyCode] = false;
}

void InputManager::Reset()
{
    memset( &_key, 0, sizeof(bool) * KeyCount);
}


bool InputManager::IsKeyDown(cocos2d::EventKeyboard::KeyCode keyCode)
{
    return _key[(int)keyCode];
}