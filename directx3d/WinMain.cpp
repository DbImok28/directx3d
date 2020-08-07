#include <Windows.h>
#include <exception>
#include <sstream>
#include "WindowsMessageMap.h"


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static WindowsMessageMap mm;
	OutputDebugStringA(mm(msg, lParam, wParam).c_str());

	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(EXIT_SUCCESS);
		break;
	case WM_KEYDOWN:
	{

	}
	break;
	case WM_KEYUP:
	{

	}
	break;
	case WM_CHAR:
	{

	}
	break;
	case WM_LBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		std::ostringstream oss;
		oss << "(" << pt.x << ", " << pt.y << ")\n";
		SetWindowTextA(hWnd, oss.str().c_str());
	}
	break;
	case WM_LBUTTONUP:
	{

	}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
								// CALLBACK #define для stdcall(соглашение для вызовов, вызываемый объект будет сам за собой очищать стек)
	HINSTANCE	hInstance,		// указатель на начало исполняемого модуля, мз сигнатуры
	HINSTANCE	hPrevInstance,	// для 16 битных систем
	LPSTR		lpCmdLine,		// команды
	int			nCmdShow)		// параметр отвечающий за то как будет показываться окно (свёрнуто, развёрнуто, на весь экран и т.д.).
{
	const auto pClassName = L"directx3d_window";
	// register window class
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = CS_OWNDC;
	wc.hInstance = hInstance;
	wc.lpszClassName = pClassName;
	wc.lpfnWndProc = WndProc; 
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.hIconSm = nullptr;

	if (!RegisterClassEx(&wc))
	{
		throw std::exception("Error to register window");
	}

	// create window instance
	HWND hWnd = CreateWindowEx(
		0, 
		pClassName,
		L"directx3d",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200,
		640, 480,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);
	if (hWnd == INVALID_HANDLE_VALUE)
	{
		throw std::exception("Error to create window");
	}

	// show window
	ShowWindow(hWnd, SW_SHOW);

	// message

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) != FALSE)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1)
		return -1;
	else
		return static_cast<int>(msg.wParam);
}