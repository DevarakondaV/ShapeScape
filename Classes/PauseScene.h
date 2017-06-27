#ifndef __PAUSESCENE_H__
#define __PAUSESCENE_H__

#include "cocos2d.h"
#include <Box2D\Box2d.h>

class ContactListener;

class PauseScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void PlayCall(cocos2d::Ref* pSender);
	void MenuCall(cocos2d::Ref* pSender);


	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);


	CREATE_FUNC(PauseScene);
};


#endif