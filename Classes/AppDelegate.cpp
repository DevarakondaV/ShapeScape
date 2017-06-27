
#include "AppDelegate.h"
#include "MainScene.h"

USING_NS_CC;
//320, 480
static cocos2d::Size designResolutionSize = cocos2d::Size(320,470);
//
static cocos2d::Size s6designResolutionSize = cocos2d::Size(360, 640);
//

static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);



AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
	
	// initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();



	if (!glview)
	{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
		glview = GLViewImpl::create("ShapeScape");
#else
		//glview = GLViewImpl::create("ShapeScape");
		//glview = GLViewImpl::createWithRect("ShapeScape", Rect(0, 0, s6designResolutionSize.width, s6designResolutionSize.height));
		glview = GLViewImpl::createWithRect("ShapeScape", Rect(0, 0, s6designResolutionSize.width, s6designResolutionSize.height));
#endif
		//glview = GLViewImpl::createWithRect("ShapeScape", Rect(0, 0, s6designResolutionSize.width, s6designResolutionSize.height));
		director->setOpenGLView(glview);
	}
	

	//getting screenSize
	auto screenSize = glview->getFrameSize(); 
	
	//setting design resolution size. Default size is 
	//glview->setDesignResolutionSize(640, 360, ResolutionPolicy::NO_BORDER);

	//File for MultiRes
	auto File = FileUtils::getInstance();
	std::vector<std::string> resDirOrders;
	
	auto m = screenSize.height/screenSize.width;
	float aspect = 1280.0 / 720.0;
	//resDirOrders.push_back("MultiResource");
	
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	{
		if (m == aspect)
		{
			resDirOrders.push_back("MultiResource/SamsungS67Edge");
			director->setContentScaleFactor(screenSize.height / designResolutionSize.height);
		}
		else
		{
			resDirOrders.push_back("MultiResource/SamsungS67Edge");
			director->setContentScaleFactor(4.5);
		}
	}
	else if (false)//CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	{
		resDirOrders.push_back("MultiResource/SamsungS67Edge");
		float scale = 1280.0 / designResolutionSize.height;
		director->setContentScaleFactor(scale);
	}

	//if (screenSize.height == 2560 || screenSize.width == 2560)// || glview->getVisibleSize().width == 360 || glview->getVisibleSize().width == 640)
	//{
	//	resDirOrders.push_back("MultiResource/SamsungS67Edge");
	//	director->setContentScaleFactor(4);
	//}
	//else if (screenSize.height == 1280 || screenSize.width == 1280)
	//{
	//	resDirOrders.push_back("MultiResource/1280x720");
	//	director->setContentScaleFactor(2);
	//}
	//else if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	//{
	//	resDirOrders.push_back("MultiResource/1280x720");
	//	director->setContentScaleFactor(2);
	//}

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	resDirOrders.push_back("Computer");
	director->setContentScaleFactor(1);
	glview->setFrameSize(360, 640);
	//resDirOrders.push_back("MultiResource/SamsungS67Edge");
	//float scale = 1440.0 / designResolutionSize.width;
	//director->setContentScaleFactor(4.5);
	//glview->setFrameSize(designResolutionSize.width, designResolutionSize.height);
#endif

	File->setSearchPaths(resDirOrders);
	glview->setDesignResolutionSize(s6designResolutionSize.width, s6designResolutionSize.height, ResolutionPolicy::NO_BORDER);


	
	register_all_packages();

	auto scene = MainScene::createScene();

	// run
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
