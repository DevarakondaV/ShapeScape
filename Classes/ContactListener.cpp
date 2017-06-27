#include "ContactListener.h"
#include "myGame.h"

ContactListener::ContactListener(myGame* GameWorldinput)
{
	GameWorld = GameWorldinput;
	contact21 = false;
}

void ContactListener::BeginContact(b2Contact* contact)
{
	auto Bodyx = contact->GetFixtureA()->GetBody();
	auto Bodyy = contact->GetFixtureB()->GetBody();

	if (Bodyx != GameWorld->getPlayerBody() && Bodyy != GameWorld->getPlayerBody())
	{
		contact21 = false;
	}
	else 
	{
		contact21 = true;
	}
}

void ContactListener::EndContact(b2Contact* contact)
{
	auto Bodyx = contact->GetFixtureA()->GetBody();
	auto Bodyy = contact->GetFixtureB()->GetBody();

	if (Bodyx != GameWorld->getPlayerBody() && Bodyy != GameWorld->getPlayerBody())
	{
		contact21 = false;
	}
	else
	{
		contact21 = true;
	}
}

void ContactListener::updateContact21()
{
	contact21 = !contact21;
}

bool ContactListener::returnContact21()
{
	return contact21;
}

