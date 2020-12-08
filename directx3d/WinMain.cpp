#include <Windows.h>
#include <exception>
#include <sstream>
#include "WindowsMessageMap.hpp"
#include "App.hpp"
#include "EngineException.hpp"


int CALLBACK WinMain(
								// CALLBACK #define для stdcall(соглашение для вызовов, вызываемый объект будет сам за собой очищать стек)
	HINSTANCE	hInstance,		// указатель на начало исполняемого модуля, мз сигнатуры
	HINSTANCE	hPrevInstance,	// для 16 битных систем
	LPSTR		lpCmdLine,		// команды
	int			nCmdShow)		// параметр отвечающий за то как будет показываться окно (свёрнуто, развёрнуто, на весь экран и т.д.).
{
	try
	{
		return App{}.Start();
	}
	catch (const EngineException& e)
	{
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBoxA(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBoxA(nullptr, "No info", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}