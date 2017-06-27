#include "MainScene.h"
#include "PlayScene.h"
#include "OptionsScene.h"
#include "SimpleAudioEngine.h"
#include "Globals.h"


bool ifSoundIsOn = false;
bool largeShapes;


float currentXPos = 0;
float currentYPos = 0;
/*
cocos2d::UserDefault *def = cocos2d::UserDefault::getInstance();
int initTime = def->getIntegerForKey("INITIALTIME", 60);
double initSize = def->getDoubleForKey("INITIALSIZE", .5);
*/

int initialTimeForTheTopShapesToDrop = 60;// initTime; //90 easy 60 medium 45 hard 30 very hard
int initialTimeForTheSideShapesToDrop = 120;//150 easy 120 medium 90 hard 60 very hard 
int initialVelocityOfShapes = 5; //4 easy 5 med 6 hard 
double initialSizeOfShapes = 0.5;//initSize;


USING_NS_CC;

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}




	UserDefault *def = UserDefault::getInstance();
	int initTime = def->getIntegerForKey("INITIALTIME", 60);
	int initSize = def->getIntegerForKey("INITIALSIZE", 2);
	

	initialTimeForTheTopShapesToDrop = initTime;// initTime; //90 easy 60 medium 45 hard 30 very hard
	initialTimeForTheSideShapesToDrop = 120;//150 easy 120 medium 90 hard 60 very hard 
	initialVelocityOfShapes = 5; //4 easy 5 med 6 hard

	switch (initSize)
	{
	case 1:
		initialSizeOfShapes = 0.4;
		break;
	case 2:
		initialSizeOfShapes = 0.5;
		break;
	case 3:
		initialSizeOfShapes = 0.7;
		break;
	}


	//ifSoundIsOn = false;

	Size visibileSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//addding background music
	if (ifSoundIsOn)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("MainMenuSound.wav", true);
	}

	//adding background
	auto BackGround = Sprite::create("MainScene1.png");
	BackGround->setAnchorPoint(Vec2(0, 0));
	BackGround->setPosition(origin.x, origin.y);
	this->addChild(BackGround);

	//adding Play button
	auto PlayItem = MenuItemImage::create("PlayButton1.png", "PlayButton2.png", CC_CALLBACK_1(MainScene::menuPlayCall, this));
	PlayItem->setAnchorPoint(Vec2(0, 0));
	auto menu = Menu::create(PlayItem, NULL);
	menu->setPosition(70,330);//100 300
	this->addChild(menu);

	//adding exit button
	auto ExitItem = MenuItemImage::create("ExitButton1.png", "ExitButton2.png", CC_CALLBACK_1(MainScene::menuCloseCallback, this));
	ExitItem -> setAnchorPoint(Vec2(0, 0));
	auto menu2 = Menu::create(ExitItem, NULL);
	menu2->setPosition(210, 80);
	this->addChild(menu2);

	//Adding Option button
	auto OptionItem = MenuItemImage::create("OptionsButton1.png", "OptionsButton2.png", CC_CALLBACK_1(MainScene::menuOptionsCall, this));
	OptionItem->setAnchorPoint(Vec2(0, 0));
	auto menu3 = Menu::create(OptionItem, NULL);
	menu3->setPosition(40, 195);
	this->addChild(menu3);

	this->setKeypadEnabled(true);
	return true;
}

void MainScene::menuCloseCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFROM == CC_PLATFORM_IOS)
	exis(0);
#endif
}


void MainScene::menuPlayCall(cocos2d::Ref* pSender)
{
	if (ifSoundIsOn)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	}
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("ClickedPlaySound.wav", true);
	auto playScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playScene);
}

void MainScene::menuOptionsCall(cocos2d::Ref* pSender)
{
	auto optionsScene = OptionsScene::createScene();
	Director::getInstance()->replaceScene(optionsScene);
}

void MainScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	// Back button pressed
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE) 
	{
		Director::getInstance()->end();
		exit(0);
	}
}

//void MainScene::menuPlayCall(cocos2d::Ref* pSender)
//{
//	
//}

/*
void MainScene::menuPlayCall(cocos2d::Ref* pSender)
{
	auto scene = PlayScene::createScene();
	Director::getInstance()->replaceScene(scene);
}*/