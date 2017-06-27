#include "SettingsScene.h"
#include "myGame.h"



USING_NS_CC;

cocos2d::Scene* SettingsScene::createScene()
{

	auto scene = Scene::create();
	auto layer = SettingsScene::create();
	scene->addChild(layer);
	return scene;
}

bool SettingsScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();//The size of the screen
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//The origin of the screen

	auto listener = EventListenerTouchOneByOne::create();//Creates listener
	listener->setSwallowTouches(true);//Sets to swallow touches

	listener->onTouchBegan = CC_CALLBACK_2(SettingsScene::onTouchBegan, this);//Implements what the program should do when a touch begins

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);//Lets the listener work

	this->scheduleUpdate();//Calls the update method

	shapesDroppedDifficulty = 60;
	shapeVelocity = 5;

	return true;//returns true


}

bool SettingsScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	bool result = false;//Returns the result of the method

	for (int i = 0; i < numOfSpritesFalling.size(); i++)//For loop that traverses the MySprites vector
	{
		if (numOfSpritesFalling[i] != nullptr)//If statement that chekcs if where we currently are traversing is not null
		{

			float x_point = touch->getLocation().x;//Sets x_point to the x location where the touch was located
			float y_point = touch->getLocation().y;//Sets y_point to the y location where the touch was located

			float x_min = numOfSpritesFalling[i]->getPosition().x;//Sets x_min to the x minimum location of the sprite we are currently traversing 
			float x_max = x_min + numOfSpritesFalling[i]->getContentSize().width;//Sets x_max to the x location of the sprite we are currently traversing

			float y_min = numOfSpritesFalling[i]->getPosition().y;//Sets y_min to the x minimum location of the sprite we are currently traversing 
			float y_max = y_min + numOfSpritesFalling[i]->getContentSize().height;//Sets y_max to the x location of the sprite we are currently traversing

			if ((x_point >= x_min) && (x_point <= x_max) && (y_point >= y_min) &&
				(y_point <= y_max))//Checks if the touch location is inside the Sprite 
			{
			
			}//Ends if statement
		}//Ends if statement
	}//Ends for-loop
	return result;//Returns the result of the method
}

int SettingsScene::setShapesDroppedDifficulty(int newShapesDroppedDifficulty)
{
	shapesDroppedDifficulty = newShapesDroppedDifficulty;
}

int SettingsScene::setShapeVelocity(int newShapeVelocity)
{
	shapeVelocity = newShapeVelocity;
}

int SettingsScene::getShapesDroppedDifficulty()
{
	return shapesDroppedDifficulty;
}

int SettingsScene::getShapeVelocity()
{
	return shapeVelocity;
}
