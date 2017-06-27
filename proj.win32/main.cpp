#include "main.h"
#include "AppDelegate.h"
#include "cocos2d.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	srand(time(NULL));
    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();
	//_CrtDumpMemoryLeaks();
	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
}
