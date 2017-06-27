#include <iostream>
#include "PlayScene.h"
#include "PauseScene.h"
#include "DeathScene.h"
#include "MainScene.h"
#include "myGame.h"
#include "B2DebugDrawLayer.h"
#include "ContactListener.h"
#include "SimpleAudioEngine.h"
#include "Globals.h"



USING_NS_CC;



PlayScene::~PlayScene()
{
	delete GameWorld;
	delete contactListener;
}

Scene* PlayScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayScene::create();
	scene->addChild(layer);
	return scene;
	
}

bool PlayScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	
	


	Size visibileSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//adding music
	if (ifSoundIsOn)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("PlayingGameSound.wav", true);
	}


	//adding background
	auto BackGround1 = Sprite::create("PlaySceneTest1.png");
	BackGround1->setAnchorPoint(Vec2(0, 0));
	BackGround1->setPosition(0,0);
	BackGround1->setOpacity(150);
	this->addChild(BackGround1,0);

	auto BackGround2 = Sprite::create("PlaySceneTest2.png");
	BackGround2->setAnchorPoint(Vec2(0, 0));
	BackGround2->setPosition(0, 0);
	this->addChild(BackGround2, 2);


	//adding Score Button
	auto ScoreItem = MenuItemImage::create("scorePlay1.png", "scorePlay2.png", CC_CALLBACK_1(PlayScene::pauseCall, this));
	ScoreItem->setAnchorPoint(Vec2(0, 0));
	auto menu = Menu::create(ScoreItem, NULL);
	menu->setPosition(20, 595);//575
	this->addChild(menu,2);
	
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PlayScene::onTouchEnded, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	score = 0;
	__String *tempScore = __String::createWithFormat("%.2f", score);
	scoreLabel = Label::createWithTTF(tempScore->getCString(), "fonts/airstrikeacad.ttf", visibileSize.height*0.07);
	scoreLabel->setColor(Color3B(255,165,0));
	scoreLabel->setPosition(Point(275, 615));
	this->addChild(scoreLabel,99);

	//adding Instructions
	__String *Instructions = __String::create("Touch and Hold to Begin");
	InstructionLabel = Label::createWithTTF(Instructions->getCString(), "fonts/airstrikeacad.ttf", visibileSize.height*0.04);
	InstructionLabel->setAnchorPoint(Point(0, 0));
	InstructionLabel->setColor(Color3B(255, 165, 0));
	InstructionLabel->setPosition(Point(5, 535));
	this->addChild(InstructionLabel, 99);



	GameWorld = new myGame();
	contactListener = new ContactListener(GameWorld);
	GameWorld->getWorld()->SetContactListener(contactListener);
	//this->addChild(B2DebugDrawLayer::create(GameWorld->getPhysics(), SCALE_RATIO), 9999);
	//GameWorld->addWall(360, 10, 0, 0);
	
	
	this->setKeypadEnabled(true);
	this->scheduleUpdate();
	return true;
}

void PlayScene::update(float dt)
{
	if (GameStarted)
	{
		contactTouched = contactListener->returnContact21();
		if (contactTouched)
		{
			this->pause();
			if (ifSoundIsOn)
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("DiedSound.wav", false);
			}
			CallFunc *runCallBack = CallFunc::create(CC_CALLBACK_0(PlayScene::DeathScene, this));
			this->runAction(Sequence::create(DelayTime::create(1.6), runCallBack, nullptr));
			
		}
		if (!GameWorld->playerExists())
		{
			GameWorld->addPlayer(xpos, ypos);
			this->addChild(GameWorld->returnPlayer(), 999);
			GameWorld->DefinePhysics(initialSizeOfShapes);
			
		}
		
		if (true)
		{
			int positionIterations = 100;
			int velocityIterations = 100;
			GameWorld->getPhysics()->Step(dt, velocityIterations, positionIterations);
			for (b2Body *body = GameWorld->getPhysics()->GetBodyList();
				body != NULL; body = body->GetNext())
			{
				if (body->GetUserData())
				{
					auto sprite = (CCSprite *)body->GetUserData();
					if (true)
					{
						sprite->setPosition(ccp(body->GetPosition().x*SCALE_RATIO, body->GetPosition().y*SCALE_RATIO));
						sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));
					}
				}
			}
			GameWorld->getPhysics()->ClearForces();
			tot++;
			GameWorld->removeSprite();

			int timeInterval = GameWorld->getTimeInterval();

			if (tot % GameWorld->getTimeInterval() == 0)
			{
				GameWorld->updateTimeInterval(GameWorld->getTimeInterval() + timeInterval);
				GameWorld->updateVelocity();
				//GameWorld->updateSideVelocity();
			}

			if (tot % GameWorld->getTimeEachShapePrintedTop() == 0 )//&& tot <= GameWorld->getTimeInterval())
			{
				GameWorld->addnewSpriteTop(GameWorld->getVelocity(),GameWorld->getSizeOfShapes());
				this->addChild(GameWorld->getSpriteVector().back()->mySprite, 1);
			}

			//if (tot % GameWorld->getTimeEachShapePrintedSides() == 0)//&& tot <= GameWorld->getTimeInterval())
			//{
			/*	GameWorld->addnewSpriteLeftSide(GameWorld->getVelocity(), GameWorld->getSizeOfShapes());
				this->addChild(GameWorld->getSpriteVector().back()->mySprite, 1);*/
			//}

			if (tot == (GameWorld->secondsToTot(GameWorld->getTimeForRightShapesToAppear())))
			{
				GameWorld->updateSwitchBetweenLeftAndRight(1);
				GameWorld->updateTimeForRightShapesToAppear(10);
			}
			else if (tot == GameWorld->secondsToTot(GameWorld->getTimeForLeftShapesToAppear()))
			{
				GameWorld->updateSwitchBetweenLeftAndRight(0);
				GameWorld->updateTimeForLeftShapesToAppear(10);
			}

			/*if ((tot == (GameWorld->secondsToTot(GameWorld->getTimeForRightShapesToAppear()))) && tot >= GameWorld->secondsToTot(15))
			{
				GameWorld->updateSideVelocity();
			}*/

			if (tot >= GameWorld->secondsToTot(10))
			{
				
				if (tot % GameWorld->getTimeEachShapePrintedSides() == 0 && GameWorld->getSwitchBetweenLeftandRight() == 0)
				{
					GameWorld->addnewSpriteLeftSide(GameWorld->getSideVelocity(), GameWorld->getSizeOfShapes());
					this->addChild(GameWorld->getSpriteVector().back()->mySprite, 1);
				}
				else if (tot % GameWorld->getTimeEachShapePrintedSides() == 0 && GameWorld->getSwitchBetweenLeftandRight() == 1)
				{
					GameWorld->addnewSpriteRightSide(GameWorld->getSideVelocity(), GameWorld->getSizeOfShapes());
					this->addChild(GameWorld->getSpriteVector().back()->mySprite, 1);
				}
			}
			
			GameWorld->updatePlayerPos(xpos, ypos);
			currentXPos = xpos; currentYPos = ypos;
		}
		score = score+dt;
		__String *tempScore = __String::createWithFormat("%.2f", score);
		scoreLabel->setString(tempScore->getCString());
	}
}

bool PlayScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	
	if (!GameStarted)
	{
		xpos = touch->getLocation().x; ypos = touch->getLocation().y;
		InstructionLabel->removeFromParentAndCleanup(true);
		GameStarted = true;
		return true;
	}
	else if (isPaused)
	{

		auto xPosOfCircleMin = UnPauseCircle->getPosition().x - 32;
		auto xPosOfCirlceMax = UnPauseCircle->getPosition().x + 32;

		auto yPosOfCircleMin = UnPauseCircle->getPosition().y;
		auto yPosOfCircleMax = UnPauseCircle->getPosition().y + 65;

		if( (touch->getLocation().x > xPosOfCircleMin && touch->getLocation().x < xPosOfCirlceMax) 
			&& (touch->getLocation().y < yPosOfCircleMax && touch->getLocation().y >yPosOfCircleMin))
		{
			this->removeChild(UnPauseCircle, true);
			this->removeChild(PauseBackground, true);
			isPaused = false; 
			Director::getInstance()->resume();
		}
		return true;
	}

	return false;
}

void PlayScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	xpos = touch->getLocation().x; ypos = touch->getLocation().y;
}

void PlayScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	if (!isPaused)
	{
		PauseBackground = Sprite::create("PauseScene1.png");
		PauseBackground->setAnchorPoint(Vec2(0, 0));
		PauseBackground->setPosition(0, 0);
		this->addChild(PauseBackground, 4);


		UnPauseCircle = Sprite::create("UnPauseButton.png");
		UnPauseCircle->setAnchorPoint(Vec2(.5, 0));
		UnPauseCircle->setPosition(currentXPos, currentYPos - 60);
		this->addChild(UnPauseCircle, 9999);

		/*auto PlayItem = MenuItemImage::create("UnPauseButton.png", "", CC_CALLBACK_1(PauseScene::PlayCall, this));
		PlayItem->setAnchorPoint(Vec2(.5, 0));
		auto menu = Menu::create(PlayItem, NULL);
		menu->setPosition(currentXPos, currentYPos - 60);
		this->addChild(menu);*/
		isPaused = true; 

		Director::getInstance()->pause();
	}

	

}

void PlayScene::pauseCall(cocos2d::Ref* pSender)
{
	auto pauseScene = PauseScene::createScene();
	Director::getInstance()->pushScene(pauseScene);
}

void PlayScene::pauseCall2()
{
	auto pauseScene = PauseScene::createScene();
	Director::getInstance()->pushScene(pauseScene);
}

void PlayScene::DeathScene()
{
	auto DeathScene = DeathScene::createScene(score);
	Director::getInstance()->replaceScene(DeathScene);
}

void PlayScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		auto MainMenuScene = MainScene::createScene();
		Director::getInstance()->resume();
		Director::getInstance()->replaceScene(MainMenuScene);
	}
}