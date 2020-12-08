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
	const float t = timer.Peek();

	std::ostringstream oss;
	oss << "time: " <<std::setprecision(1) << std::fixed <<t<< "s";
	wnd.SetTitle(oss.str());
}
