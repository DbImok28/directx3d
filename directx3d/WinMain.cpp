#include <Windows.h>
#include <exception>
#include <sstream>
#include "WindowsMessageMap.hpp"
#include "Window.hpp"
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
	Window wnd(800, 600, "directWindow");

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) != FALSE)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			MessageBox(nullptr, "bla-bla-bla", "aga", MB_OK);
		}
	}
	if (gResult == -1)
		return -1;
	return 0;
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