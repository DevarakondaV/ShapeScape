#ifndef __SIZEOFSHAPESSCENE_H__
#define __SIZEOFSHAPESSCENE_H__
#include "cocos2d.h"

class SizeOfShapesScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void update(float dt3);

	void SmallDiffCallback();
	void MediumDiffCallback();
	void LargeDiffCallback();
	void menuCallBack(cocos2d::Ref* pSender);

	void deleteSprites();

	CREATE_FUNC(SizeOfShapesScene);

private:
	std::vector<cocos2d::Sprite*> spriteHolder;

};

#endif