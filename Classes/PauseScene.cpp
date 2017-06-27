#include "PauseScene.h"
#include "DeathScene.h"
#include "Globals.h"

USING_NS_CC;


Scene* PauseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PauseScene::create();
	scene->addChild(layer);
	return scene;
}

bool PauseScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	Size visibileSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//adding Background
	auto BackGround = Sprite::create("PauseScene1.png");
	BackGround->setAnchorPoint(Vec2(0, 0));
	BackGround->setPosition(origin.x, origin.y);
	this->addChild(BackGround);

	//adding Play button
	//auto PlayItem = MenuItemImage::create("UnPauseButton.png", "", CC_CALLBACK_1(PauseScene::PlayCall, this));
	//PlayItem->setAnchorPoint(Vec2(.5, 0));
	//auto menu = Menu::create(PlayItem, NULL);
	//menu->setPosition(currentXPos, currentYPos - 60);
	//this->addChild(menu);

	auto Player = Sprite::create("Player-min.png");
	Player->setAnchorPoint(Vec2(.5, 0));
	Player->setPosition(currentXPos, currentYPos +4);
	//Player->setScale(.8);
	this->addChild(Player);


	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(PauseScene::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	////adding Menu button
	//auto MenuItem = MenuItemImage::create("MenuDeath1.png", "MenuDeath2.png", CC_CALLBACK_1(PauseScene::MenuCall, this));
	//MenuItem->setAnchorPoint(Vec2(0, 0));
	//auto Menu2 = Menu::create(MenuItem, NULL);
	//Menu2->setPosition(100, 50);
	//this->addChild(Menu2);

	

	return true;


}


//void PauseScene::PlayCall(cocos2d::Ref* pSender)
//{
//	Director::getInstance()->popScene();
//}

bool PauseScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	Director::getInstance()->popScene();
	return true;
}

void PauseScene::MenuCall(cocos2d::Ref* pSender)
{
	//auto deathScene = DeathScene::createScene();
	//Director::getInstance()->popToRootScene();
	//Director::getInstance()->replaceScene(deathScene);
}