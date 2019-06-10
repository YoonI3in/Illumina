#include "Recognizer.h"
#include "TestManager.h"

bool Recognizer::init()
{

	if (TestManager::getInstance()->currentStage == 4) {

		recognizer1 = Sprite::create("RecognizerOff.png");
		this->addChild(recognizer1, 1);

		recognizer2 = Sprite::create("RecognizerOff.png");
		this->addChild(recognizer2, 1);

		recognizer1->setPosition(583, 288);

		recognizer2->setPosition(697, 288);
		recognizer2->setFlipX(true);

		TestManager::getInstance()->_recognizer2 = recognizer2;
	}
	else if (TestManager::getInstance()->currentStage == 5) {

		recognizer1 = Sprite::create("RecognizerOff.png");
		this->addChild(recognizer1, 1);

		recognizer1->setPosition(617, 96);
	}
	else if (TestManager::getInstance()->currentStage == 6) {
		recognizer1 = Sprite::create("RecognizerOff.png");
		recognizer1->setRotation(-90.0f);
		this->addChild(recognizer1, 1);

		recognizer1->setPosition(480, 752);

		recognizer2 = Sprite::create("RecognizerOff.png");
		recognizer2->setRotation(-90.0f);
		this->addChild(recognizer2, 1);

		recognizer2->setPosition(864, 752);

		recognizer3 = Sprite::create("RecognizerOff.png");
		recognizer3->setRotation(-90.0f);
		this->addChild(recognizer3, 1);

		recognizer3->setPosition(1120, 752);

		TestManager::getInstance()->_recognizer2 = recognizer2;
		TestManager::getInstance()->_recognizer3 = recognizer3;
	}
	TestManager::getInstance()->_recognizer1 = recognizer1;


	this->scheduleUpdate();

	return true;
}