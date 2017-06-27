#include "NewScene.h"
#include "PlayScene.h"
#include "MainScene.h"

USING_NS_CC;

Scene* NewScene::createScene()
{
	auto scene = Scene::create();
	auto layer = NewScene::create();
	scene->addChild(layer);
	return scene;
}

bool NewScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto BackGround = Sprite::create("TwitchBackground.png");
	BackGround->setAnchorPoint(Vec2(0, 0));
	BackGround->setPosition(origin.x, origin.y);
	this->addChild(BackGround);

	auto MenuItem = MenuItemImage::create("MenuDeath1.png", "MenuDeath2.png", CC_CALLBACK_1(NewScene::MenuCall, this));
	MenuItem->setAnchorPoint(Vec2(0, 0));
	auto menu = Menu::create(MenuItem, NULL);
	menu->setPosition(50, 100);
	this->addChild(menu);

	auto PlayItem = MenuItemImage::create("PlayButton1.png", "PlayButton2.png", CC_CALLBACK_1(NewScene::PlayCall, this));
	PlayItem->setAnchorPoint(Vec2(0, 0));
	auto menu2 = Menu::create(PlayItem, NULL);
	menu2->setPosition(100, 150);
	this->addChild(menu2);

	return true;
}

void NewScene::MenuCall(cocos2d::Ref* pSender)
{
	auto menuScene = MainScene::createScene();
	Director::getInstance()->replaceScene(menuScene);
}

void NewScene::PlayCall(cocos2d::Ref* pSender)
{
	auto menuScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(menuScene);
}
