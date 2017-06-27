#ifndef __CONTACTLISTENER_H__
#define __CONTACTLISTENER_H__

#include "cocos2d.h"
#include <Box2D\Box2d.h>


class myGame;
class ContactListener :public b2ContactListener
{
public:
	ContactListener(myGame* GameWorldinput);
	virtual void BeginContact(b2Contact* contact);
	virtual void EndContact(b2Contact* contact);
	void updateContact21();
	bool returnContact21();

private:
	bool contact21 = false;
	myGame* GameWorld;
};
#endif
