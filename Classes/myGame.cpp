#include "myGame.h"
#include "string"
#include <cstdlib>





USING_NS_CC;


//###########################################################################################
//Function Declerations
//###########################################################################################
std::string return_File_Name(int Num);
std::string random_File();


//###########################################################################################
//myGame Class Constructors/Destructors
//###########################################################################################
myGame::myGame()
{
	previousPosTop = 10000;
	previousPosLeft = 10000;
	b2Vec2 gravity = b2Vec2(0.0f, 0.0f);// -7.0f);
	world = new b2World(gravity);
	timeEachShapePrintedTop = initialTimeForTheTopShapesToDrop;
	timeEachShapePrintedSides = initialTimeForTheSideShapesToDrop;
	velocity = initialVelocityOfShapes;
	sizeOfShapes = initialSizeOfShapes;
	sideVelocity = 4;

}
myGame::~myGame()
{
	delete world;
	for (size_t i = 0; i < SpriteContainer.size(); i++)
	{
		delete SpriteContainer[i];
	}
}


//###########################################################################################
//My Game Player Method Definitions
//###########################################################################################
void myGame::addPlayer(float xPos, float yPos)
{
	m_player = Sprite::create("Player-min1.png");
	m_player->setPosition(xPos, yPos + 60);
	DefinePlayer(1, xPos, yPos + 60);
}

bool myGame::playerExists()
{
	if (m_player == nullptr)
		return false;
	else
		return true;
}

void myGame::updatePlayerPos(float x_move, float y_move)
{
	//360 640
	auto Anchor = m_player->getAnchorPointInPoints();	
	auto xmin = x_move - Anchor.x;
	auto xmax = x_move + Anchor.x;
	auto ymax = (y_move + 60) + Anchor.y;
	if (xmin > 0 && xmax<360 &&
		y_move>0 && ymax < 565)
	{
		removePlayerFixture();
		DefinePlayer(1, x_move, y_move + 60);
		b2Vec2 pos = PlayerBody->GetPosition();
		//m_player->setPosition(x_move, y_move + 15);
		m_player->setPosition(pos.x*SCALE_RATIO, pos.y*SCALE_RATIO);
	}
}

cocos2d::Sprite* myGame::returnPlayer()
{
	return m_player;
}


//###########################################################################################
//My Game Sprite Method Definitions
//###########################################################################################
void myGame::addnewSpriteTop(float Velocity, float Scale)
{
	if (true)
	{
		//srand(time(NULL));
		float position1;
		if (initialSizeOfShapes == .4)
		{
			position1 = rand() % 9;
		}
		else if (initialSizeOfShapes == .5)
		{
			position1 = rand() % 8;
		}
		else if (initialSizeOfShapes == .7)
		{
			position1 = rand() % 7;
		}

		if (previousPosTop == 10000)
		{
			previousPosTop = position1;
		}
		
		while (previousPosTop == position1)
		{
			if (initialSizeOfShapes == .4)
			{
				position1 = rand() % 9;
			}
			else if (initialSizeOfShapes == .5)
			{
				position1 = rand() % 8;
			}
			else if (initialSizeOfShapes == .7)
			{
				position1 = rand() % 7;
			}
		}
		previousPosTop = position1;
		auto val = random_File();
		spriteCont* SNode = new spriteCont;
		SNode->mySprite = Sprite::create(val);
		//SNode->mySprite->setAnchorPoint(Vec2(0, 0));

		if (val[0] == 'T')
		{
			SNode->SpriteBodyDef.type = b2_dynamicBody;
			SNode->SpriteBodyDef.userData = SNode->mySprite;
			SNode->SpriteBodyDef.position.Set(random_Top_Sprite(position1)/SCALE_RATIO, 600/SCALE_RATIO);
			SNode->SpriteBody = world->CreateBody(&SNode->SpriteBodyDef);
			SNode->SpriteBody->CreateFixture(&TriangleFixture);
			SNode->SpriteBody->SetGravityScale(1);

		}
		else if (val[0] == 'C')
		{
			SNode->SpriteBodyDef.type = b2_dynamicBody;
			SNode->SpriteBodyDef.userData = SNode->mySprite;
			SNode->SpriteBodyDef.position.Set(random_Top_Sprite(position1) / SCALE_RATIO, 600 / SCALE_RATIO);
			SNode->SpriteBody = world->CreateBody(&SNode->SpriteBodyDef);
			SNode->SpriteBody->CreateFixture(&CircleFixture);
			SNode->SpriteBody->SetGravityScale(1);
		}
		else
		{
			SNode->SpriteBodyDef.type = b2_dynamicBody;
			SNode->SpriteBodyDef.userData = SNode->mySprite;
			SNode->SpriteBodyDef.position.Set(random_Top_Sprite(position1) / SCALE_RATIO, 600 / SCALE_RATIO);
			SNode->SpriteBody = world->CreateBody(&SNode->SpriteBodyDef);
			SNode->SpriteBody->CreateFixture(&SquareFixture);
			SNode->SpriteBody->SetGravityScale(1);
			//SNode->SpriteBody->SetUserData((void*)shapes);
		}
		//SNode->SpriteBody->SetUserData((void*)shapes);
		auto pos = SNode->SpriteBody->GetPosition();
		auto size = SNode->mySprite->getContentSize();
		SNode->mySprite->setPosition(pos.x*SCALE_RATIO, pos.y*SCALE_RATIO);
		SNode->SpriteBody->SetLinearVelocity(b2Vec2(0.0f, -Velocity));
		SNode->mySprite->setScale(Scale);
		SpriteContainer.push_back(SNode);
	}
}

int myGame::random_Top_Sprite(int num)
{
	
	
	
	if(initialSizeOfShapes == .7)
	{ 
		switch (num) {
		case 0:
			return ONE;
		case 1:
			return TWO;
		case 2:
			return THREE;
		case 3:
			return FOUR;
		case 4:
			return FIVE;
		case 5:
			return SIX;
		case 6:
			return SEVEN;
		
		}
	}
	else if (initialSizeOfShapes == .5)
	{
		switch (num) {
		case 0:
			return ONE;
		case 1:
			return TWO;
		case 2:
			return THREE;
		case 3:
			return FOUR;
		case 4:
			return FIVE;
		case 5:
			return SIX;
		case 6:
			return SEVEN;
		case 7:
			return EIGHT;

		}
	}
	else if (initialSizeOfShapes == .4)
	{
		switch (num) {
		case 0:
			return ONE;
		case 1:
			return TWO;
		case 2:
			return THREE;
		case 3:
			return FOUR;
		case 4:
			return FIVE;
		case 5:
			return SIX;
		case 6:
			return SEVEN;
		case 7:
			return EIGHT;
		case 8: 
			return NINE;

		}
	}

	return -1;

}

void myGame::addnewSpriteLeftSide(float Velocity, float Scale)
{
	if (true)
	{
		//srand(time(NULL));
		float position1 = 0;
		auto val = random_File();
		spriteCont* SNode = new spriteCont;
		SNode->mySprite = Sprite::create(val);
		//SNode->mySprite->setAnchorPoint(Vec2(0, 0));

		if (val[0] == 'T')
		{
			SNode->SpriteBodyDef.type = b2_dynamicBody;
			SNode->SpriteBodyDef.userData = SNode->mySprite;
			SNode->SpriteBodyDef.position.Set(-(5 / SCALE_RATIO), random_Left_Sprite(position1) / SCALE_RATIO);
			SNode->SpriteBody = world->CreateBody(&SNode->SpriteBodyDef);
			SNode->SpriteBody->CreateFixture(&TriangleFixture);
			SNode->SpriteBody->SetGravityScale(1);

		}
		else if (val[0] == 'C')
		{
			SNode->SpriteBodyDef.type = b2_dynamicBody;
			SNode->SpriteBodyDef.userData = SNode->mySprite;
			SNode->SpriteBodyDef.position.Set(-(5 / SCALE_RATIO), random_Left_Sprite(position1) / SCALE_RATIO);
			SNode->SpriteBody = world->CreateBody(&SNode->SpriteBodyDef);
			SNode->SpriteBody->CreateFixture(&CircleFixture);
			SNode->SpriteBody->SetGravityScale(1);
		}
		else
		{
			SNode->SpriteBodyDef.type = b2_dynamicBody;
			SNode->SpriteBodyDef.userData = SNode->mySprite;
			SNode->SpriteBodyDef.position.Set(-(5 / SCALE_RATIO), random_Left_Sprite(position1) / SCALE_RATIO);
			SNode->SpriteBody = world->CreateBody(&SNode->SpriteBodyDef);
			SNode->SpriteBody->CreateFixture(&SquareFixture);
			SNode->SpriteBody->SetGravityScale(1);
			//SNode->SpriteBody->SetUserData((void*)shapes);
		}
		//SNode->SpriteBody->SetUserData((void*)shapes);
		auto pos = SNode->SpriteBody->GetPosition();
		auto size = SNode->mySprite->getContentSize();
		SNode->mySprite->setPosition(pos.x*SCALE_RATIO, pos.y*SCALE_RATIO);
		SNode->SpriteBody->SetLinearVelocity(b2Vec2(5.0f, -7.0));
		SNode->mySprite->setScale(Scale);
		SpriteContainer.push_back(SNode);
	}
}

int myGame::random_Left_Sprite(int num)
{
	switch (num) {
	case 0:
		return TOP_LEFT;
	//case 1:
	//	return SECOND_TOP_LEFT;
	//*case 2:
	//	return THIRD_TOP_LEFT;
	//case 3:
	//	return FOURTH_TOP_LEFT;*/
	}


	return -1;

}

void myGame::addnewSpriteRightSide(float Velocity, float Scale)
{
	if (true)
	{
		//srand(time(NULL));
		float position1 = 0;
		auto val = random_File();
		spriteCont* SNode = new spriteCont;
		SNode->mySprite = Sprite::create(val);
		//SNode->mySprite->setAnchorPoint(Vec2(0, 0));

		if (val[0] == 'T')
		{
			SNode->SpriteBodyDef.type = b2_dynamicBody;
			SNode->SpriteBodyDef.userData = SNode->mySprite;
			SNode->SpriteBodyDef.position.Set(XPOS_FOR_RIGHT / SCALE_RATIO, random_Right_Sprite(position1) / SCALE_RATIO);
			SNode->SpriteBody = world->CreateBody(&SNode->SpriteBodyDef);
			SNode->SpriteBody->CreateFixture(&TriangleFixture);
			SNode->SpriteBody->SetGravityScale(1);

		}
		else if (val[0] == 'C')
		{
			SNode->SpriteBodyDef.type = b2_dynamicBody;
			SNode->SpriteBodyDef.userData = SNode->mySprite;
			SNode->SpriteBodyDef.position.Set(XPOS_FOR_RIGHT / SCALE_RATIO, random_Right_Sprite(position1) / SCALE_RATIO);
			SNode->SpriteBody = world->CreateBody(&SNode->SpriteBodyDef);
			SNode->SpriteBody->CreateFixture(&CircleFixture);
			SNode->SpriteBody->SetGravityScale(1);
		}
		else
		{
			SNode->SpriteBodyDef.type = b2_dynamicBody;
			SNode->SpriteBodyDef.userData = SNode->mySprite;
			SNode->SpriteBodyDef.position.Set(XPOS_FOR_RIGHT / SCALE_RATIO, random_Right_Sprite(position1) / SCALE_RATIO);
			SNode->SpriteBody = world->CreateBody(&SNode->SpriteBodyDef);
			SNode->SpriteBody->CreateFixture(&SquareFixture);
			SNode->SpriteBody->SetGravityScale(1);
			//SNode->SpriteBody->SetUserData((void*)shapes);
		}
		//SNode->SpriteBody->SetUserData((void*)shapes);
		auto pos = SNode->SpriteBody->GetPosition();
		auto size = SNode->mySprite->getContentSize();
		SNode->mySprite->setPosition(pos.x*SCALE_RATIO, pos.y*SCALE_RATIO);
		SNode->SpriteBody->SetLinearVelocity(b2Vec2(-5.0f, -7.0));
		SNode->mySprite->setScale(Scale);
		SpriteContainer.push_back(SNode);
	}
}

int myGame::random_Right_Sprite(int num)
{
	switch (num) {
	case 0:
		return TOP_RIGHT;
		//case 1:
		//	return SECOND_TOP_LEFT;
		//*case 2:
		//	return THIRD_TOP_LEFT;
		//case 3:
		//	return FOURTH_TOP_LEFT;*/
	}
	return -1;
}

void myGame::removeSprite() 
{
	std::vector<int> indexes;
	for (size_t i = 0; i < SpriteContainer.size(); i++)
	{
		auto size = SpriteContainer[i]->mySprite->getContentSize();
		auto topPixel = SpriteContainer[i]->mySprite->getPosition().y + (size.height/2);
		//auto topPixel = SpriteContainer[i]->mySprite->getPosition().y + size.height;
		if (topPixel <= 0)
		{
			indexes.push_back(i);
		}
	}

	for (size_t i = 0; i < SpriteContainer.size(); i++)
	{
		auto pos = SpriteContainer[i]->mySprite->getPosition();
		if (pos.x < -50 || pos.x>410)
		{
			indexes.push_back(i);
		}
	}


	for (size_t i = 0; i < indexes.size(); i++)
	{
		SpriteContainer[indexes[i]]->mySprite->removeFromParentAndCleanup(true);
		world->DestroyBody(SpriteContainer[indexes[i]]->SpriteBody);
		delete SpriteContainer[indexes[i]];
		SpriteContainer.erase(SpriteContainer.begin() + indexes[i]);
	}
}

int myGame::getNumberSpirtes() 
{
	return SpriteContainer.size();
}

const std::vector<spriteCont *>& myGame::getSpriteVector()
{
	return SpriteContainer;
}

//###########################################################################################
//My Game Physics World Method Definitions
//###########################################################################################
b2World* myGame::getPhysics()
{
	return world;
}

void myGame::DefinePhysics(float spriteScale)
{
	auto Circle = Sprite::create("CircleDB.png");
	auto Triangle = Sprite::create("TriangleDB.png");
	auto Square = Sprite::create("SquareDB.png");



	//defining circle.
	auto CircSize = Circle->getContentSize();
	auto Scaled = spriteScale*(CircSize);
	auto Radius = ((Scaled.x) / 2)-4;

	CircleShape.m_radius = Radius / SCALE_RATIO;
	CircleFixture.density = 10.0f;
	CircleFixture.friction = 0.8f;
	CircleFixture.restitution = 0.3f;
	CircleFixture.shape = &CircleShape;


	//defining Triangle.
	auto TriSize = Triangle->getContentSize();
	auto height = ((TriSize.height) - 10) / 2;
	b2Vec2 Vertices[3];
	int32 count = 3;
	Vertices[0].Set(float(0), float((spriteScale*(height)) / SCALE_RATIO));
	Vertices[1].Set(float((spriteScale*(-height)) / SCALE_RATIO), float((spriteScale*(-height)) / SCALE_RATIO));
	Vertices[2].Set(float((spriteScale*(height)) / SCALE_RATIO), float((spriteScale*(-height)) / SCALE_RATIO));
	TriangleShape.Set(Vertices, count);
	TriangleFixture.density = 10.0f;
	TriangleFixture.friction = 0.8f;
	TriangleFixture.restitution = 0.3f;
	TriangleFixture.shape = &TriangleShape;


	//defining square.
	auto SquareSize = Square->getContentSize();
	auto h = (SquareSize.height)-10;
	SquareShape.SetAsBox((spriteScale*(h/2)) / SCALE_RATIO, (spriteScale*(h/2)) / SCALE_RATIO);
	SquareFixture.density = 10.0;
	SquareFixture.friction = 0.8;
	SquareFixture.restitution = 0.3;
	SquareFixture.shape = &SquareShape;
}

void myGame::DefinePlayer(float spriteScale, float xpos, float ypos)
{
	auto playerSize = m_player->getContentSize();

	b2Vec2 Vertices[3];
	int32 count = 3;
	auto len = (playerSize.height / 2) - 4;
	Vertices[0].Set(float(0), float(spriteScale*(len) / SCALE_RATIO));
	Vertices[1].Set(float((spriteScale*(-len)) / SCALE_RATIO), float((spriteScale*(-len)) / SCALE_RATIO));
	Vertices[2].Set(float((spriteScale*(len)) / SCALE_RATIO), float((spriteScale*(-len)) / SCALE_RATIO));
	PlayerShape.Set(Vertices, count);
	PlayerFixture.density = 10.0f;
	PlayerFixture.friction = 0.8;
	PlayerFixture.restitution = 0.3;
	PlayerFixture.shape = &PlayerShape;
	PlayerBodyDef.userData = m_player;
	PlayerBodyDef.position.Set((xpos) / SCALE_RATIO, (ypos) / SCALE_RATIO);
	PlayerBody = world->CreateBody(&PlayerBodyDef);
	PlayerBody->CreateFixture(&PlayerFixture);
	PlayerBody->SetGravityScale(0.0f);
	PlayerBody->SetFixedRotation(true);
	//PlayerBody->SetUserData((void*)player);

}

void myGame::removePlayerFixture()
{
	world->DestroyBody(PlayerBody);
}

void myGame::addWall(float w, float h, float px, float py)
{
	b2PolygonShape floorshape;
	floorshape.SetAsBox(w / SCALE_RATIO, h / SCALE_RATIO);
	b2FixtureDef floorFixture;
	floorFixture.density = 0;
	floorFixture.friction = 10;
	floorFixture.restitution = 0.5;
	floorFixture.shape = &floorshape;
	b2BodyDef floorBodyDef;
	floorBodyDef.position.Set(px / SCALE_RATIO, py / SCALE_RATIO);
	b2Body *floorBody = world->CreateBody(&floorBodyDef);
	floorBody->CreateFixture(&floorFixture);
}

b2Body* myGame::getPlayerBody()
{
	return PlayerBody;
}

b2World* myGame::getWorld()
{
	return world;
}

//###########################################################################################
//Other Helper Functions
//###########################################################################################
void myGame::updateTimeEachShapePrintedTop(int update)
{
	timeEachShapePrintedTop = update;
}

void myGame::updateTimeEachShapePrintedSides(int update)
{
	timeEachShapePrintedSides = update;
}

void myGame::updateTimeInterval(int update)
{
	timeInterval = update;
}

void myGame::updateVelocity()
{
	velocity++;
}

////void myGame::updateSideVelocity()
//{
//	sideVelocity++;
//}

void myGame::updateSwitchBetweenLeftAndRight(int update)
{
	switchBetweenLeftAndRight = update;
}

void myGame::updateSizeOfShapes(int update)
{
	sizeOfShapes = update;
}

void myGame::updateSpeedIncrease(int update)
{
	speedIncrease = update;
}

void myGame::updateTimeForLeftShapesToAppear(int update)
{
	timeForLeftShapesToAppear = timeForLeftShapesToAppear + update;
}

void myGame::updateTimeForRightShapesToAppear(int update)
{
	timeForRightShapesToAppear = timeForRightShapesToAppear + update;
}

int myGame::getTimeEachShapePrintedTop()
{
	return timeEachShapePrintedTop;
}

int myGame::getTimeEachShapePrintedSides()
{
	return timeEachShapePrintedSides;
}

int myGame::getTimeInterval()
{
	return timeInterval;
}

int myGame::getVelocity()
{
	return velocity;
}

int myGame::getSideVelocity()
{
	return sideVelocity;
}

int myGame::getSwitchBetweenLeftandRight()
{
	return switchBetweenLeftAndRight;
}

float myGame::getSizeOfShapes()
{
	return sizeOfShapes;
}

int myGame::getSpeedIncrease()
{
	return speedIncrease;
}

int myGame::getTimeForLeftShapesToAppear()
{
	return timeForLeftShapesToAppear;
}

int myGame::getTimeForRightShapesToAppear()
{
	return timeForRightShapesToAppear;
}

int myGame::secondsToTot(int seconds)
{
	return (seconds * 60);
}


//###########################################################################################
//Function Definitions
//###########################################################################################
std::string return_File_Name(int Num)
{
	switch (Num) {
	case CIRCLE_DB:
		return "CircleDB.png";
	case CIRCLE_G:
		return "CircleG.png";
	case CIRCLE_P:
		return "CircleP.png";
	case CIRCLE_R:
		return "CircleR.png";
	case SQUARE_DB:
		return "SquareDB.png";
	case SQUARE_G:
		return "SquareG.png";
	case SQUARE_P:
		return "SquareP.png";
	case SQUARE_R:
		return "SquareR.png";
	case TRIANGLE_DB:
		return "TriangleDB.png";
	case TRIANGLE_G:
		return "TriangleG.png";
	case TRIANGLE_P:
		return "TriangleP.png";
	case TRIANGLE_R:
		return "TriangleR.png";
	}

	return "";
}

std::string random_File()
{
	//srand(time(NULL));
	return	return_File_Name(rand()%12);//rand()%12);

}
