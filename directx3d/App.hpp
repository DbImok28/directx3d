#pragma once
#include "Window.hpp"
#include "Timer.hpp"

class App
{
public:
	App() : App(800, 600, "directx app") {};
	App(int width, int height, const char* name);
	~App();
	int Start();
private:
	void Frame();
private:
	Window wnd;
	Timer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};