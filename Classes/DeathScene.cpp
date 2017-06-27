#include "DeathScene.h"
#include "PlayScene.h"
#include "MainScene.h"
#include "Globals.h"


USING_NS_CC;

float inScore;
Scene* DeathScene::createScene(float input_Score)
{
	inScore = input_Score;
	auto scene = Scene::create();
	auto layer = DeathScene::create();
	scene->addChild(layer);
	return scene;
}

bool DeathScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	inputScore = inScore;


	//rounding inputScore
	/*int iScore = inputScore;
	double act = inputScore - iScore;
	act = act * 10;
	int act2 = act;
	if (act2 >= 5)
	{
		iScore++;
	}

	inputScore = iScore;*/

	//CCLog("Score: %.2f", inputScore);
	Size visibileSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//adding Background
	auto BackGround = Sprite::create("DeathScene.png");
	BackGround->setAnchorPoint(Vec2(0, 0));
	BackGround->setPosition(origin.x, origin.y);
	this->addChild(BackGround);


	//adding Play button
	auto PlayItem = MenuItemImage::create("PlayButtonForDeathScene1.png", "PlayButtonForDeathScene2.png", CC_CALLBACK_1(DeathScene::PlayCall, this));
	PlayItem->setAnchorPoint(Vec2(0, 0));
	auto menu = Menu::create(PlayItem, NULL);
	menu->setPosition(35, 70);
	this->addChild(menu);

	//add Menu Button
	auto menuItem = MenuItemImage::create("MenuForDeathScene1.png", "MenuForDeathScene2.png", CC_CALLBACK_1(DeathScene::MenuCall, this));
	menuItem->setAnchorPoint(Vec2(0, 0));
	auto menu2 = Menu::create(menuItem, NULL);
	menu2->setPosition(215, 70);
	this->addChild(menu2);
	

	UserDefault *def = UserDefault::getInstance();

	if (initialSizeOfShapes == .4 && initialTimeForTheTopShapesToDrop == 60)
	{
		highscore = def->getFloatForKey("SEHIGHSCORE",0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("SEHIGHSCORE",highscore);
		}
	}
	else if (initialSizeOfShapes == .4 && initialTimeForTheTopShapesToDrop == 45)
	{
		highscore = def->getFloatForKey("SMHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("SMHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .4 && initialTimeForTheTopShapesToDrop == 30)
	{
		highscore = def->getFloatForKey("SHHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("SHHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .4 && initialTimeForTheTopShapesToDrop == 15)
	{
		highscore = def->getFloatForKey("SEXHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("SEXHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .5 && initialTimeForTheTopShapesToDrop == 60)
	{
		highscore = def->getFloatForKey("MEHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("MEHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .5 && initialTimeForTheTopShapesToDrop == 45)
	{
		highscore = def->getFloatForKey("MMHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("MMHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .5 && initialTimeForTheTopShapesToDrop == 30)
	{
		highscore = def->getFloatForKey("MHHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("MHHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .5 && initialTimeForTheTopShapesToDrop == 15)
	{
		highscore = def->getFloatForKey("MEXHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("MEXHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .7 && initialTimeForTheTopShapesToDrop == 60)
	{
		highscore = def->getFloatForKey("LEHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("LEHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .7 && initialTimeForTheTopShapesToDrop == 45)
	{
		highscore = def->getFloatForKey("LMHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("LMHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .7 &&  initialTimeForTheTopShapesToDrop == 30)
	{
		highscore = def->getFloatForKey("LHHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("LHHIGHSCORE", highscore);
		}
	}
	else if (initialSizeOfShapes == .7 && initialTimeForTheTopShapesToDrop == 15)
	{
		highscore = def->getFloatForKey("LEXHIGHSCORE", 0.0);

		if (inputScore > highscore)
		{
			highscore = inputScore;
			def->setFloatForKey("LEXHIGHSCORE", highscore);
		}
	}

	def->flush();

	__String *score = __String::createWithFormat("%.2f", inputScore);
	auto currentScore = Label::createWithTTF(score->getCString(), "fonts/airstrikeacad.ttf", visibileSize.height*0.1);
	currentScore->setColor(Color3B(0, 250, 0));
	currentScore->setPosition(Point(185, 460));
	this->addChild(currentScore);

	__String *highScore = __String::createWithFormat("%.2f", highscore);
	auto highScoreLabel = Label::createWithTTF(highScore->getCString(), "fonts/airstrikeacad.ttf", visibileSize.height*0.1);
	highScoreLabel->setColor(Color3B(61,29,255));
	highScoreLabel->setPosition(Point(185,340 ));
	this->addChild(highScoreLabel);


	auto easy1 = Sprite::create("EasyButton1.png");
	easy1->setAnchorPoint(Vec2(0, 0));
	easy1->setPosition(30, 175);
	easy1->setScale(.7);

	auto medium1 = Sprite::create("MediumButton1.png");
	medium1->setAnchorPoint(Vec2(0, 0));
	medium1->setPosition(0, 170);
	medium1->setScale(.85);

	auto hard1 = Sprite::create("HardButton1.png");
	hard1->setAnchorPoint(Vec2(0, 0));
	hard1->setPosition(20, 170);
	hard1->setScale(.7);

	auto expert1 = Sprite::create("ExpertButton1.png");
	expert1->setAnchorPoint(Vec2(0, 0));
	expert1->setPosition(0, 173);
	expert1->setScale(.85);


	auto small1 = Sprite::create("Small1.png");
	small1->setAnchorPoint(Vec2(0, 0));
	small1->setPosition(195, 175);
	small1->setScale(.8);

	auto medium2 = Sprite::create("MediumButton1.png");
	medium2->setAnchorPoint(Vec2(0, 0));
	medium2->setPosition(190, 171);
	medium2->setScale(.9);

	auto large1 = Sprite::create("Large1.png");
	large1->setAnchorPoint(Vec2(0, 0));
	large1->setPosition(200, 175);
	large1->setScale(.85);

	if (initialSizeOfShapes == .4)
	{
		this->addChild(small1);
	}
	else if (initialSizeOfShapes == .5)
	{
		this->addChild(medium2);
	}
	else if (initialSizeOfShapes == .7)
	{
		this->addChild(large1);
	}

	if (initialTimeForTheTopShapesToDrop == 60)
	{
		this->addChild(easy1);
	}
	else if (initialTimeForTheTopShapesToDrop == 45)
	{
		this->addChild(medium1);
	}
	else if (initialTimeForTheTopShapesToDrop == 30)
	{
		this->addChild(hard1);
	}
	else if (initialTimeForTheTopShapesToDrop == 15)
	{
		this->addChild(expert1);
	}

	this->setKeypadEnabled(true);
	return true;
}

void DeathScene::PlayCall(cocos2d::Ref* pSender)
{
	auto playScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playScene);
}

void DeathScene::MenuCall(cocos2d::Ref* pSender)
{
	auto mainScene = MainScene::createScene();
	Director::getInstance()->replaceScene(mainScene);
}

void DeathScene::printString(std::string printedString)
{
	Size visibileSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto stringLabel = Label::createWithTTF(printedString, "fonts/arial.ttf", visibileSize.height*0.1);
	stringLabel->setColor(Color3B(61, 29, 255));
	stringLabel->setPosition(Point(185, 340));
	this->addChild(stringLabel);

}

void DeathScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		auto mainScene = MainScene::createScene();
		Director::getInstance()->replaceScene(mainScene);
	}
}