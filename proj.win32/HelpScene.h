#ifndef __HELPSCENE_H__
#define __HELPSCENE_H__

#include "cocos2d.h"

class HelpScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCall(cocos2d::Ref* pSender);
};

#endif