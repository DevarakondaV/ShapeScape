#ifndef __PAUSESCENE_H__
#define __PAUSESCENE_H__

#include "cocos2d.h"

class PauseScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void QuitCallBack(cocos2d:::Ref* pSender);
	void ExitCallBack(cocos2d::Ref* pSender);

	CREATE_FUNC(PauseScene)
};

#endif