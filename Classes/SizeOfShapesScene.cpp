#include "SizeOfShapesScene.h"
#include "Globals.h"
#include "OptionsScene.h"

USING_NS_CC;

Scene* SizeOfShapesScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SizeOfShapesScene::create();
	scene->addChild(layer);
	return scene;
}

bool SizeOfShapesScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibileSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto BackGround = Sprite::create("SizesOfShapesScene.png");
	BackGround->setAnchorPoint(Vec2(0, 0));
	BackGround->setPosition(0, 0);
	this->addChild(BackGround);

	auto BackItem = MenuItemImage::create("BackButton1.png", "BackButton2.png", CC_CALLBACK_1(SizeOfShapesScene::menuCallBack, this));
	BackItem->setAnchorPoint(Vec2(0, 0));
	auto backButton = Menu::create(BackItem, NULL);
	backButton->setPosition(31, 55);
	this->addChild(backButton);

	auto box = Sprite::create("BoxForSizes.png");
	box->setAnchorPoint(Vec2(.5, .5));
	box->setPosition(270, 100);
	this->addChild(box);
	box->runAction(RepeatForever::create(RotateBy::create(2.5f, 180.f)));
	//this->addChild(box);


	/*auto smallSprite = Sprite::create("Small1.png");
	smallSprite->setAnchorPoint(Vec2(0, 0));
	smallSprite->setPosition(91, 503);
	this->addChild(smallSprite);

	auto mediumSprite = Sprite::create("MediumButton1.png");
	mediumSprite->setAnchorPoint(Vec2(0, 0));
	mediumSprite->setPosition(86, 363);
	this->addChild(mediumSprite);


	auto hardSprite = Sprite::create("Large1.png");
	hardSprite->setAnchorPoint(Vec2(0,0));
	hardSprite->setPosition(86, 235);
	this->addChild(hardSprite);*/
	
	auto SmallDifficultyItem = MenuItemImage::create("InvisibleBox.png", "", CC_CALLBACK_0(SizeOfShapesScene::SmallDiffCallback, this));
	SmallDifficultyItem->setAnchorPoint(Vec2(0, 0));
	auto small1 = Menu::create(SmallDifficultyItem, NULL);
	small1->setPosition(88, 480);
	this->addChild(small1);

	auto MediumDifficultyItem = MenuItemImage::create("InvisibleBox.png", "", CC_CALLBACK_0(SizeOfShapesScene::MediumDiffCallback, this));
	MediumDifficultyItem->setAnchorPoint(Vec2(0, 0));
	auto medium = Menu::create(MediumDifficultyItem, NULL);
	medium->setPosition(86, 344);
	this->addChild(medium);

	auto LargeDifficultyItem = MenuItemImage::create("InvisibleBox.png", "", CC_CALLBACK_0(SizeOfShapesScene::LargeDiffCallback, this));
	LargeDifficultyItem->setAnchorPoint(Vec2(0, 0));
	auto large = Menu::create(LargeDifficultyItem, NULL);
	large->setPosition(86, 209);
	this->addChild(large);


	this->scheduleUpdate();
	return true;



}


void SizeOfShapesScene::update(float dt2)
{
	deleteSprites();

	auto small1 = Sprite::create("Small1.png");
	small1->setAnchorPoint(Vec2(0, 0));
	small1->setPosition(91, 503);

	auto small2 = Sprite::create("Small2.png");
	small2->setAnchorPoint(Vec2(0, 0));
	small2->setPosition(91, 503);

	auto medium1 = Sprite::create("MediumButton1.png");
	medium1->setAnchorPoint(Vec2(0, 0));
	medium1->setPosition(86, 363);

	auto medium2 = Sprite::create("MediumButton2.png");
	medium2->setAnchorPoint(Vec2(0, 0));
	medium2->setPosition(86, 363);

	auto large1 = Sprite::create("Large1.png");
	large1->setAnchorPoint(Vec2(0, 0));
	large1->setPosition(86, 235);

	auto large2 = Sprite::create("Large2.png");
	large2->setAnchorPoint(Vec2(0, 0));
	large2->setPosition(86, 235);


	if (initialSizeOfShapes == .4)
	{
		this->addChild(small2);
		spriteHolder.push_back(small2);

		this->addChild(medium1);
		spriteHolder.push_back(medium1);

		this->addChild(large1);
		spriteHolder.push_back(large1);

	}
	else if (initialSizeOfShapes == .5)
	{
		this->addChild(small1);
		spriteHolder.push_back(small1);

		this->addChild(medium2);
		spriteHolder.push_back(medium2);

		this->addChild(large1);
		spriteHolder.push_back(large1);

	}
	else if (initialSizeOfShapes == .7)
	{
		this->addChild(small1);
		spriteHolder.push_back(small1);

		this->addChild(medium1);
		spriteHolder.push_back(medium1);

		this->addChild(large2);
		spriteHolder.push_back(large2);

	}
}

void SizeOfShapesScene::SmallDiffCallback()
{
	UserDefault *def = UserDefault::getInstance();
	def->setIntegerForKey("INITIALSIZE", 1);
	//largeShapes = false;
	initialSizeOfShapes = .4;

}

void SizeOfShapesScene::MediumDiffCallback()
{
	UserDefault *def = UserDefault::getInstance();
	def->setIntegerForKey("INITIALSIZE", 2);
	//largeShapes = false;	
	initialSizeOfShapes = .5;	
	
}

void SizeOfShapesScene::LargeDiffCallback()
{
	UserDefault *def = UserDefault::getInstance();
	def->setIntegerForKey("INITIALSIZE", 3);
	//largeShapes = true; 
	initialSizeOfShapes = .7;
}


void SizeOfShapesScene::deleteSprites()
{
	for (size_t i = 0; i < spriteHolder.size(); i++)
	{
		this->removeChild(spriteHolder[i], true);
	}
}

void SizeOfShapesScene::menuCallBack(cocos2d::Ref* pSender)
{

	auto OptionsScene = OptionsScene::createScene();
	Director::getInstance()->replaceScene(OptionsScene);
}

