#ifndef __GLOBALS_H__
#define __GLOBALS_H__

//struct difficulties
//{
//	std::string nameOfDifficulty;
//	bool isActive;
//	int startingTimeForTopShapesToFall;
//	int startingTimeForSideShapesToFall;
//	int startingTopVelocity;
//	int startingSideVelocity;
//};


const int CIRCLE_DB = 0;
const int CIRCLE_G = 1;
const int CIRCLE_P = 2;
const int CIRCLE_R = 3;
const int SQUARE_DB = 4;
const int SQUARE_G = 5;
const int SQUARE_P = 6;
const int SQUARE_R = 7;
const int TRIANGLE_DB = 8;
const int TRIANGLE_G = 9;
const int TRIANGLE_P = 10;
const int TRIANGLE_R = 11;

const int THREE = 190;
const int TWO = 125;
const int ONE = 60;
const int FOUR = 245;
const int FIVE = 290;
const int SIX = 340;
const int SEVEN = 380;
const int EIGHT = 20;
const int NINE = 0;



const int TOP_LEFT = 640;
//const int SECOND_TOP_LEFT = 570;
//const int THIRD_TOP_LEFT = 520;
//const int FOURTH_TOP_LEFT = 450;

const int TOP_RIGHT = 640;
const int XPOS_FOR_RIGHT = 400;

extern bool largeShapes;

//extern int shapeSize;

//extern int holdingDifficultyForNumberOfShapes; //= 0;
//extern int holdingSizeOfShapes;

extern int initialTimeForTheTopShapesToDrop; //= 90; //90 easy 60 medium 45 hard 30 very hard
extern int initialTimeForTheSideShapesToDrop; //= 150;//150 easy 120 medium 90 hard 60 very hard 
extern int initialVelocityOfShapes; //= 6; //4 easy 5 med 6 hard 
extern double initialSizeOfShapes;


extern float currentXPos;
extern float currentYPos;


extern bool ifSoundIsOn;

//vector<difficulties> settings;




//const int shapes = 123;
//const int player = 012;

  
#endif // !__GLOBALS_H__

