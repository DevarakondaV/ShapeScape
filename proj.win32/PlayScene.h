#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "cocos2d.h"

class PlayScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void PauseCall(cocos2d::Ref* pSender);

	CREATE_FUNC(PlayScene);
};


#endif