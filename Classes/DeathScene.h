#ifndef __DEATHSCENE_H__
#define __DEATHSCENE_H__


#include "cocos2d.h"

class DeathScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene(float input_Score);
	virtual bool init();
	void PlayCall(cocos2d::Ref* pSender);
	void MenuCall(cocos2d::Ref* pSender);

	void printString(std::string printedString);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);


	CREATE_FUNC(DeathScene)
private:
	float inputScore;
	float highscore;
};

#endif