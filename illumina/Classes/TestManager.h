#pragma once

#include "cocos2d.h"

//싱글톤을 이용한 클래스

class Box;
class Mirror;
class Button;
class TestManager
{
public:
	static TestManager* getInstance()
	{
		static TestManager instance;
		return &instance;
	}

	~TestManager()
	{
	}
public:
	//전역적으로 참조할만한 데이터를 이곳에 넣어서 사용한다.
	bool space				= 0;
	bool pick				= 0;
	bool holding			= 0;
	bool red1On				= 0;
	bool red2On				= 0;
	bool greenOn			= 0;
	bool blueOn				= 0;
	bool pressed			= 0;
	bool open				= 0;
	bool laser1Reflected	= 0;
	bool laser2Reflected	= 0;
	bool laser3Reflected = 0;
	bool rightDir			= 1;
	
	int currentStage;
	int zNum				= 11;

	cocos2d::Node*	 _target		 = nullptr;

	Box* _currentPickBox			 = nullptr;
	cocos2d::Layer* _boxLayer		 = nullptr;

	Mirror* _currentPickMirror		 = nullptr;
	Mirror* _currentReflectMirror	 = nullptr;
	cocos2d::Layer* _mirrorLayer	 = nullptr;

	Button* _currentPressedButton	 = nullptr;
	cocos2d::Layer*	_buttonLayer	 = nullptr;
	 
	cocos2d::Sprite* _red1			 = nullptr;
	cocos2d::Sprite* _red2			 = nullptr;
	cocos2d::Sprite* _green1		 = nullptr;
	cocos2d::Sprite* _green2		 = nullptr;
	cocos2d::Sprite* _blue1			 = nullptr;
	cocos2d::Sprite* _blue2			 = nullptr;
	cocos2d::Sprite* _verticalLaser1 = nullptr;
	cocos2d::Sprite* _verticalLaser2 = nullptr;
	cocos2d::Sprite* _verticalLaser3 = nullptr;
	cocos2d::Sprite* _horizontalLaser1 = nullptr;
	cocos2d::Sprite* _horizontalLaser2 = nullptr;
	cocos2d::Sprite* _horizontalLaser3 = nullptr;
	cocos2d::Sprite* _recognizer1	= nullptr;
	cocos2d::Sprite* _recognizer2	= nullptr;
	cocos2d::Sprite* _recognizer3 = nullptr;

	//cocos2d::Sprite* _RedLight		= nullptr;
};