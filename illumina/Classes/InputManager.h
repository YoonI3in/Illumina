//
//  InputManager.hpp
//  Sample
//
//  Created by aheanuri on 2016. 7. 13..
//
//
#pragma once
#include "cocos2d.h"

#define GlobalIntputManager InputManager::getInstance()

//KEY_PLAY가 마지막 enum element...
const static int KeyCount = (int)cocos2d::EventKeyboard::KeyCode::KEY_PLAY+1;

class InputManager
{
    
public:
    static InputManager* getInstance()
    {
        static InputManager instance;
        
        if( instance.IsInitialized() == false )
        {
            instance.Initialize();
        }
        
        return &instance;
    }
    
    bool IsInitialized()
    {
        return _initialized;
    }
    
    bool IsKeyDown(cocos2d::EventKeyboard::KeyCode keyCode);
    
    void Initialize();
    void Reset();
    
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    
protected:
    bool _initialized = false;
    
    cocos2d::EventListenerKeyboard* _keyboardListener = nullptr;
    
    bool _key[KeyCount];
};