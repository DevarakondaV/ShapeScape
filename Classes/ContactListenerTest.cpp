#include "cocos2d.h"
#include <Box2D\Box2d.h>
#include "ContactListenerTest.h"

ContactListenerTest::ContactListenerTest()
{
	contact21 = false;
}

void ContactListenerTest::BeginContact(b2Contact* contact)
{
	auto x = contact->GetFixtureA()->GetUserData();
	auto y = contact->GetFixtureB()->GetUserData();

	if (x == y)
	{
		contact21 = true;
	}
}

void ContactListenerTest::EndContact(b2Contact* contact)
{
	auto x = contact->GetFixtureA()->GetUserData();
	auto y = contact->GetFixtureB()->GetUserData();
	if (x == y)
	{
		contact21 = true;
	}
}

void ContactListenerTest::updateContact21()
{
	contact21 = !contact21;
}

bool ContactListenerTest::returnContact21()
{
	return contact21;
}

