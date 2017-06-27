#ifndef __NEWSCENE_H__
#define __NEWSCENE_H__

#include "cocos2d.h"

class NewScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void MenuCall(cocos2d::Ref* pSender);
	void PlayCall(cocos2d::Ref* pSender);

	CREATE_FUNC(NewScene)
};

#endif
