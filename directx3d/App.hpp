#pragma once
#include "Window.hpp"

class App
{
public:
	App() : App(800, 600, "directx app") {};
	App(int width, int height, const char* name);
	int Start();
private:
	void Frame();
private:
	Window wnd;
};

