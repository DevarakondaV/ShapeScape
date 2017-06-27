#include "PlayScene.h"

USING_NS_CC;


Scene* PlayScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayScene::create();
	scene->addChild(layer);
	return scene;
}


bool PlayScene::init()
{
	return false;
}
