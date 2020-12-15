#include "App.hpp"
#include <sstream>
#include <iomanip>

App::App(int width, int height, const char* name) : wnd(width, height, name){}

int App::Start()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		Frame();
	}
	
}

void App::Frame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.GetGraphics().ClearBuffer(c, c, 1.0f);

	wnd.GetGraphics().DrawTestTriangle(timer.Peek());




	wnd.GetGraphics().EndFrame();
}
