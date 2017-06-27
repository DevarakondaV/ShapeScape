#ifndef __MAINSCENE_H__
#define __MAINSCENE_H__

#include "cocos2d.h"



class MainScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void menuPlayCall(cocos2d::Ref* pSender);
	void menuOptionsCall(cocos2d::Ref* pSender);
	void menuHelpCall(cocos2d::Ref* pSender);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	CREATE_FUNC(MainScene);
};

#endif