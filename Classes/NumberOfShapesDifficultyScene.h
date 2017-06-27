#ifndef __NUMBEROFSHAPESDIFFICULTYSCENE_H__
#define __NUMBEROFSHAPESDIFFICULTYSCENE_H__

#include "cocos2d.h"

class NumberOfShapesDifficultyScene : public cocos2d::Layer
{
public: 
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void update(float dt3);

	void EasyDiffCallback();
	void MediumDiffCallback();
	void HardDiffCallback();
	void ExpertDiffCallback();

	void menuBackCall(cocos2d::Ref* pSender);

	void deleteSprites();

	CREATE_FUNC(NumberOfShapesDifficultyScene);

private:
	bool isEasyActive;
	bool isMediumActive;
	bool isHardActive;
	bool isExpertActive;


	std::vector<cocos2d::Sprite*> spriteHolder;

};
#endif // !__NUMBEROFSHAPESDIFFICULTYSCENE_H__

#pragma once
