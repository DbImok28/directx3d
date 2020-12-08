#include "App.hpp"

App::App(int width, int height, const char* name) : wnd(width, height, name)
{

}

int App::Start()
{
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) != FALSE)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		Frame();
	}
	if (gResult == -1)
	{
		throw WND_LAST_EXCEPT();
	}
	return msg.wParam;
}

void App::Frame()
{
}
