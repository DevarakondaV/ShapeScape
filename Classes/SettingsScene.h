#ifndef __SETTINGSSCENE_H__
#define __SETTINGSSCENE_H__

#include "cocos2d.h"



class SettingsScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);//Method that tells the program what to do when a touch begins

	int setShapesDroppedDifficulty(int newShapesDroppedDifficulty);
	int setShapeVelocity(int newShapeVelocity);

	static int getShapesDroppedDifficulty();
	static int getShapeVelocity();
	

	CREATE_FUNC(SettingsScene);

private:
	
	std::vector<cocos2d::Sprite*> numOfSpritesFalling;
	std::vector<cocos2d::Sprite*> speedOfSprites;
	
	static int shapesDroppedDifficulty;
	static int shapeVelocity;


};



#endif // !__SETTINGSSCENE_H__

