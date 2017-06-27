#ifndef __MYGAME_H__
#define __MYGAME_H__
#define SCALE_RATIO 50

#include "cocos2d.h"
#include "Globals.h"
#include <Box2D\Box2D.h>



struct spriteCont
{
	cocos2d::Sprite* mySprite;
	b2BodyDef SpriteBodyDef;
	b2Body *SpriteBody;
	b2Draw* dbgDraw;
	
};



class myGame
{
public:
	myGame();
	~myGame();

	 
	//###########################################################################################
	//Sprite Methods
	//###########################################################################################
	void addnewSprite();
	void addnewSpriteTop(float Velocity, float Scale);
	void addnewSpriteLeftSide(float Velocity, float Scale);
	void addnewSpriteRightSide(float Velocity, float Scale);
	void removeSprite();
	bool Player_Sprite_overlap();
	int random_Top_Sprite(int num);
	int random_Left_Sprite(int num);
	int random_Right_Sprite(int num);
	
	
	//###########################################################################################
	//Physics World methods
	//###########################################################################################
	b2World* getPhysics();
	b2World* getWorld();
	void DefinePhysics(float spriteScale);
	void DefinePlayer(float spriteScale, float xpos, float ypos);
	void addWall(float w, float h, float px, float py);
	void removePlayerFixture();
	b2Body* getPlayerBody();

	
	
	//###########################################################################################
	//Sprite Vector Methods
	//###########################################################################################
	int getNumberSpirtes();
	const std::vector<spriteCont*>& getSpriteVector();
	

	//###########################################################################################
	//Player Methods
	//###########################################################################################
	void addPlayer(float xPos, float yPos);
	cocos2d::Sprite* returnPlayer();
	bool playerExists();
	void updatePlayerPos(float x_move, float y_move);
	void updateSpritePos(float x_move, float y_move);


	//###########################################################################################
	//Game Logic Methods
	//###########################################################################################
	void updateTimeEachShapePrintedTop(int update);
	void updateTimeEachShapePrintedSides(int update);
	void updateTimeInterval(int update);
	void updateVelocity();
	//void updateSideVelocity();
	void updateSwitchBetweenLeftAndRight(int update);
	void updateSizeOfShapes(int update);
	void updateSpeedIncrease(int update);
	void updateTimeForLeftShapesToAppear(int update);
	void updateTimeForRightShapesToAppear(int update);
	int getTimeEachShapePrintedTop();
	int getTimeEachShapePrintedSides();
	int getTimeInterval();
	int getVelocity();
	int getSideVelocity();
	int getSwitchBetweenLeftandRight();
	float getSizeOfShapes();
	int getSpeedIncrease();
	int getTimeForLeftShapesToAppear();
	int getTimeForRightShapesToAppear();
	int secondsToTot(int seconds);




private:

	//###########################################################################################
	//Game logic Vairable
	//###########################################################################################
	int timeEachShapePrintedTop;
	int timeEachShapePrintedSides;
	int timeInterval = 300;
	int velocity;
	int sideVelocity;
	int switchBetweenLeftAndRight = 0;
	float sizeOfShapes;
	int speedIncrease = 1;
	int timeForLeftShapesToAppear = 10;
	int timeForRightShapesToAppear = 15;
	int timeForRightToAppear = 10;
	float previousPosTop;
	float previousPosLeft;
	float previousPosRight;
	
	


	//###########################################################################################
	//Player Variables
	//###########################################################################################
	cocos2d::Sprite* m_player = nullptr;
	b2FixtureDef PlayerFixture;
	b2PolygonShape PlayerShape;
	b2BodyDef PlayerBodyDef;
	b2Body *PlayerBody;
	


	//###########################################################################################
	//Physics World Variables
	//###########################################################################################
	b2World *world;
	b2FixtureDef CircleFixture;
	b2FixtureDef TriangleFixture;
	b2FixtureDef SquareFixture;
	b2PolygonShape TriangleShape;
	b2PolygonShape SquareShape;
	b2CircleShape CircleShape;


	//###########################################################################################
	//Other Variables
	//###########################################################################################
	std::vector<spriteCont *> SpriteContainer;
};





#endif
