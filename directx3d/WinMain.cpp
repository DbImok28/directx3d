#include <Windows.h>
#include <exception>
#include <sstream>
#include "WindowsMessageMap.h"
#include "Window.h"
#include "EngineException.hpp"


int CALLBACK WinMain(
								// CALLBACK #define ��� stdcall(���������� ��� �������, ���������� ������ ����� ��� �� ����� ������� ����)
	HINSTANCE	hInstance,		// ��������� �� ������ ������������ ������, �� ���������
	HINSTANCE	hPrevInstance,	// ��� 16 ������ ������
	LPSTR		lpCmdLine,		// �������
	int			nCmdShow)		// �������� ���������� �� �� ��� ����� ������������ ���� (�������, ���������, �� ���� ����� � �.�.).
{
	try
	{
	Window wnd(800, 300, "direcWindow");
	Window wnd2(300, 100, "direcWindow2");

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) != FALSE)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
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