#include "NumberOfShapesDifficultyScene.h"
#include "Globals.h"
#include "OptionsScene.h"

USING_NS_CC;

Scene* NumberOfShapesDifficultyScene::createScene()
{
	auto scene = Scene::create();
	auto layer = NumberOfShapesDifficultyScene::create();
	scene->addChild(layer);
	return scene;
}

bool NumberOfShapesDifficultyScene::init()
{
	if (!Layer::init())
	{
		return false; 
	}
	Size visibileSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto BackGround = Sprite::create("ChoosingDifficultyScene.png");
	BackGround->setAnchorPoint(Vec2(0, 0));
	BackGround->setPosition(0, 0);
	this->addChild(BackGround);

	auto BackItem = MenuItemImage::create("BackButton1.png", "BackButton2.png", CC_CALLBACK_1(NumberOfShapesDifficultyScene::menuBackCall, this));
	BackItem->setAnchorPoint(Vec2(0, 0));
	auto backButton = Menu::create(BackItem, NULL);
	backButton->setPosition(31, 55);
	this->addChild(backButton);

	auto EasyDifficultyItem = MenuItemImage::create("InvisibleBox.png", "", CC_CALLBACK_0(NumberOfShapesDifficultyScene::EasyDiffCallback,this));
	EasyDifficultyItem->setAnchorPoint(Vec2(0, 0));
	auto easy = Menu::create(EasyDifficultyItem, NULL);
	easy->setPosition(89, 470);
	this->addChild(easy);

	auto MediumDifficultyItem = MenuItemImage::create("InvisibleBox.png", "", CC_CALLBACK_0(NumberOfShapesDifficultyScene::MediumDiffCallback, this));
	MediumDifficultyItem->setAnchorPoint(Vec2(0, 0));
	auto medium = Menu::create(MediumDifficultyItem, NULL);
	medium->setPosition(89, 360);
	this->addChild(medium);

	auto HardDifficultyItem = MenuItemImage::create("InvisibleBox.png", "", CC_CALLBACK_0(NumberOfShapesDifficultyScene::HardDiffCallback, this));
	HardDifficultyItem->setAnchorPoint(Vec2(0, 0));
	auto hard = Menu::create(HardDifficultyItem, NULL);
	hard->setPosition(89, 245);
	this->addChild(hard);

	auto ExpertDifficultyItem = MenuItemImage::create("InvisibleBox.png", "", CC_CALLBACK_0(NumberOfShapesDifficultyScene::ExpertDiffCallback, this));
	ExpertDifficultyItem->setAnchorPoint(Vec2(0, 0));
	auto expert = Menu::create(ExpertDifficultyItem, NULL);
	expert->setPosition(89, 132);
	this->addChild(expert);

	this->scheduleUpdate();
	return true;

	

}

void NumberOfShapesDifficultyScene::update(float dt2)
{
	deleteSprites();

	auto easy1 = Sprite::create("EasyButton1.png");
	easy1->setAnchorPoint(Vec2(0, 0));
	easy1->setPosition(89, 490);
	
	auto easy2 = Sprite::create("EasyButton2.png");
	easy2->setAnchorPoint(Vec2(0, 0));
	easy2->setPosition(89, 490);

	auto medium1 = Sprite::create("MediumButton1.png");
	medium1->setAnchorPoint(Vec2(0, 0));
	medium1->setPosition(86, 380);

	auto medium2 = Sprite::create("MediumButton2.png");
	medium2->setAnchorPoint(Vec2(0, 0));
	medium2->setPosition(86, 380);

	auto hard1 = Sprite::create("HardButton1.png");
	hard1->setAnchorPoint(Vec2(0, 0));
	hard1->setPosition(87, 265);

	auto hard2 = Sprite::create("HardButton2.png");
	hard2->setAnchorPoint(Vec2(0, 0));
	hard2->setPosition(87, 265);

	auto expert1 = Sprite::create("ExpertButton1.png");
	expert1->setAnchorPoint(Vec2(0, 0));
	expert1->setPosition(84, 160);

	auto expert2 = Sprite::create("ExpertButton2.png");
	expert2->setAnchorPoint(Vec2(0, 0));
	expert2->setPosition(84, 160);

	if ( initialTimeForTheTopShapesToDrop == 60)
	{
		this->addChild(easy2);
		spriteHolder.push_back(easy2);

		this->addChild(medium1);
		spriteHolder.push_back(medium1);

		this->addChild(hard1);
		spriteHolder.push_back(hard1);

		this->addChild(expert1);
		spriteHolder.push_back(expert1);
	}
	else if (initialTimeForTheTopShapesToDrop == 45)
	{
		this->addChild(easy1);
		spriteHolder.push_back(easy1);

		this->addChild(medium2);
		spriteHolder.push_back(medium2);

		this->addChild(hard1);
		spriteHolder.push_back(hard1);

		this->addChild(expert1);
		spriteHolder.push_back(expert1);
	}
	else if (initialTimeForTheTopShapesToDrop == 30)
	{
		this->addChild(easy1);
		spriteHolder.push_back(easy1);

		this->addChild(medium1);
		spriteHolder.push_back(medium1);

		this->addChild(hard2);
		spriteHolder.push_back(hard2);

		this->addChild(expert1);
		spriteHolder.push_back(expert1);
	}
	else if (initialTimeForTheTopShapesToDrop == 15)
	{
		this->addChild(easy1);
		spriteHolder.push_back(easy1);

		this->addChild(medium1);
		spriteHolder.push_back(medium1);

		this->addChild(hard1);
		spriteHolder.push_back(hard1);

		this->addChild(expert2);
		spriteHolder.push_back(expert2);
	}
}

void NumberOfShapesDifficultyScene::EasyDiffCallback()
{
	UserDefault *def = UserDefault::getInstance();
	def->setIntegerForKey("INITIALTIME", 60);
	initialTimeForTheTopShapesToDrop = 60;
	initialTimeForTheSideShapesToDrop = 150;
	initialVelocityOfShapes = 4;
}

void NumberOfShapesDifficultyScene::MediumDiffCallback()
{
	UserDefault *def = UserDefault::getInstance();
	def->setIntegerForKey("INITIALTIME", 45);
	initialTimeForTheTopShapesToDrop = 45;
	initialTimeForTheSideShapesToDrop = 120;
	initialVelocityOfShapes = 5;
}

void NumberOfShapesDifficultyScene::HardDiffCallback()
{
	UserDefault *def = UserDefault::getInstance();
	def->setIntegerForKey("INITIALTIME", 30);
	initialTimeForTheTopShapesToDrop = 30;
	initialTimeForTheSideShapesToDrop = 90;
	initialVelocityOfShapes = 6;
}

void NumberOfShapesDifficultyScene::ExpertDiffCallback()
{
	UserDefault *def = UserDefault::getInstance();
	def->setIntegerForKey("INITIALTIME", 15);
	initialTimeForTheTopShapesToDrop = 15;
	initialTimeForTheSideShapesToDrop = 60;
	initialVelocityOfShapes = 6;
}

void NumberOfShapesDifficultyScene::deleteSprites()
{
	for (size_t i = 0; i < spriteHolder.size(); i++)
	{
		this->removeChild(spriteHolder[i], true);
	}
}

void NumberOfShapesDifficultyScene::menuBackCall(cocos2d::Ref* pSender)
{
	auto OptionsScene = OptionsScene::createScene();
	Director::getInstance()->replaceScene(OptionsScene);
}

