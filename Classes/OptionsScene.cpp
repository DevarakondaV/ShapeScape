#include "OptionsScene.h"
#include "Globals.h"
#include "NumberOfShapesDifficultyScene.h"
#include "SimpleAudioEngine.h"
#include "MainScene.h"
#include "SizeOfShapesScene.h"

USING_NS_CC;

Scene* OptionsScene::createScene()
{
	auto scene = Scene::create();
	auto layer = OptionsScene::create();
	scene->addChild(layer);
	return scene;
}

bool OptionsScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibileSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto BackGround = Sprite::create("OptionsScene.png");
	BackGround->setAnchorPoint(Vec2(0, 0));
	BackGround->setPosition(0, 0);
	this->addChild(BackGround);

	auto NumOfShapesDifficultyItem = MenuItemImage::create("NumOfShapesButton1.png", "", CC_CALLBACK_1(OptionsScene::menuNumberOfShapesDifficultyCall, this));
	NumOfShapesDifficultyItem->setAnchorPoint(Vec2(0, 0));
	auto menu = Menu::create(NumOfShapesDifficultyItem, NULL);
	menu->setPosition(87, 345);
	this->addChild(menu);

	auto BackItem = MenuItemImage::create("BackButton1.png", "BackButton2.png", CC_CALLBACK_1(OptionsScene::menuBackCall, this));
	BackItem->setAnchorPoint(Vec2(0, 0));
	auto backButton = Menu::create(BackItem, NULL);
	backButton->setPosition(15, 40);
	this->addChild(backButton);
	
	auto SizesItem = MenuItemImage::create("SizeOfShapes1.png", "SizeOfShapes2.png", CC_CALLBACK_1(OptionsScene::menuSizeOfShapesCall, this));
	SizesItem->setAnchorPoint(Vec2(0, 0));
	auto sizesButton = Menu::create(SizesItem, NULL);
	sizesButton->setPosition(90, 215);
	this->addChild(sizesButton);
	/*auto velocityButton = Sprite::create("VelocityButtonNotActive.png");
	velocityButton->setAnchorPoint(Vec2(0, 0));
	velocityButton->setPosition(76, 232);
	this->addChild(velocityButton);*/

	auto OnButtonItem = MenuItemImage::create("InvisibleOnButton.png", "", CC_CALLBACK_0(OptionsScene::turnOnButtonCall, this));
	OnButtonItem->setAnchorPoint(Vec2(0, 0));
	auto menu2 = Menu::create(OnButtonItem, NULL);
	menu2->setPosition(165, 137);
	this->addChild(menu2);

	auto OffButtonItem = MenuItemImage::create("InvisibleOffButtonForOptionsScene.png", "", CC_CALLBACK_0(OptionsScene::turnOffButtonCall, this));
	OffButtonItem->setAnchorPoint(Vec2(0, 0));
	auto menu3 = Menu::create(OffButtonItem, NULL);
	menu3->setPosition(264, 137);
	this->addChild(menu3);
	



	this->setKeypadEnabled(true);
	this->scheduleUpdate();
	
	
	return true;

}

void OptionsScene::update(float dt2)
{
	if (soundWasJustTurnedOn)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("MainMenuSound.wav", true);
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();//playBackgroundMusic("MainMenuSound.wav", true);
		soundWasJustTurnedOn = false;
	}
	
	if (soundWasJustTurnedOff)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		soundWasJustTurnedOff = false;
	}
	

	deleteSprites();

	auto onButton1 = Sprite::create("OnButton1.png");
	onButton1->setAnchorPoint(Vec2(0, 0));
	onButton1->setPosition(165, 137);
	//spriteHolder.push_back(onButton1);

	auto onButton2 = Sprite::create("OnButton2.png");
	onButton2->setAnchorPoint(Vec2(0, 0));
	onButton2->setPosition(165, 137);
	//spriteHolder.push_back(onButton2);

	auto offButton1 = Sprite::create("OffButton1.png");
	offButton1->setAnchorPoint(Vec2(0, 0));
	offButton1->setPosition(265, 137);
	//spriteHolder.push_back(offButton1);

	auto offButton2 = Sprite::create("OffButton2.png");
	offButton2->setAnchorPoint(Vec2(0, 0));
	offButton2->setPosition(265, 137);
	//spriteHolder.push_back(offButton2);

	if (ifSoundIsOn)
	{
		this->addChild(onButton2);
		spriteHolder.push_back(onButton2);
		this->addChild(offButton1);
		spriteHolder.push_back(offButton1);
	}
	else
	{
		this->addChild(onButton1);
		spriteHolder.push_back(onButton1);
		this->addChild(offButton2);
		spriteHolder.push_back(offButton2);
	}
}

void OptionsScene::menuNumberOfShapesDifficultyCall(cocos2d::Ref* pSender)
{
	auto NumberOfShapesDifficultyScene = NumberOfShapesDifficultyScene::createScene();
	Director::getInstance()->replaceScene(NumberOfShapesDifficultyScene);
}

void OptionsScene::menuSizeOfShapesCall(cocos2d::Ref* pSender)
{
	auto SizeOfShapesScene = SizeOfShapesScene::createScene();
	Director::getInstance()->replaceScene(SizeOfShapesScene);
}

void OptionsScene::menuBackCall(cocos2d::Ref* pSender)
{
	auto MainMenuScene = MainScene::createScene();
	Director::getInstance()->replaceScene(MainMenuScene);
}

void OptionsScene::turnOnButtonCall()
{
	if (!ifSoundIsOn)
	{
		ifSoundIsOn = true;
		soundWasJustTurnedOn = true;
	}
}

void OptionsScene::turnOffButtonCall()
{
	if (ifSoundIsOn)
	{
		ifSoundIsOn = false;
		soundWasJustTurnedOff = true;
	}
}

void OptionsScene::deleteSprites()
{
	for (size_t i = 0; i < spriteHolder.size(); i++)
	{
		this->removeChild(spriteHolder[i], true);
	}
}


void OptionsScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE) 
	{
		auto MainMenuScene = MainScene::createScene();
		Director::getInstance()->replaceScene(MainMenuScene);
	}
}
