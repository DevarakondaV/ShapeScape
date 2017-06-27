#ifndef __OPTIONSSCENE_H__
#define __OPTIONSSCENE_H__

#include "cocos2d.h"


class OptionsScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void update(float dt2);
	void deleteSprites();
	void menuNumberOfShapesDifficultyCall(cocos2d::Ref* pSender);
	void menuSizeOfShapesCall(cocos2d::Ref* pSender);
	void menuBackCall(cocos2d::Ref* pSender);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);


	void checkSound();
	void turnOnButtonCall();
	void turnOffButtonCall();




	//bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	//void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);

	CREATE_FUNC(OptionsScene);
private:
	std::vector<cocos2d::Sprite*> spriteHolder;
	bool soundWasJustTurnedOn;
	bool soundWasJustTurnedOff;
};
#endif // !__OPTIONSSCENE_H__
