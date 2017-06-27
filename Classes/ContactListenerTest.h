#ifndef __CONTACTLISTENERTEST_H__
#define __CONTACTLISTENERTEST_H__

#include "cocos2d.h"
#include <Box2D\Box2d.h>


class ContactListenerTest:public b2ContactListener
{
public:
	ContactListenerTest();
	virtual void BeginContact(b2Contact* contact);
	virtual void EndContact(b2Contact* contact);
	void updateContact21();
	bool returnContact21();
	
private:
	bool contact21 = false;

};

#endif
