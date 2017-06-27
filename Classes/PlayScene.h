#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "cocos2d.h"
#include <Box2D\Box2d.h>



class myGame;
class ContactListener;

class PlayScene :public cocos2d::Layer
{
public:
	~PlayScene();
	static cocos2d::Scene* createScene();
	virtual bool init();
	void pauseCall(cocos2d::Ref* pSender);
	void pauseCall2();
	void DeathScene();
	virtual void update(float dt);


	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	

	CREATE_FUNC(PlayScene);

private:

	
	//###########################################################################################
	//Contact Listener and Game World. Dynamically Allocated Data
	//###########################################################################################
	ContactListener* contactListener;
	myGame* GameWorld;

	//###########################################################################################
	//Helper Variables
	//###########################################################################################
	bool contactTouched;
	bool GameStarted = false;
	bool playerExists = true;
	bool isPaused = false;

	cocos2d::Sprite* PauseBackground;
	cocos2d::Sprite* UnPauseCircle;

	//###########################################################################################
	//Touch Coordinates
	//###########################################################################################
	float xpos = -5;
	float ypos = -5;
	int currentTouchID;

	int tot = 0;
	float score;
	cocos2d::Label *scoreLabel;
	cocos2d::Label *InstructionLabel;
};




#endif