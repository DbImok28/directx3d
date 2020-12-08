#include <Windows.h>
#include <exception>
#include <sstream>
#include "WindowsMessageMap.hpp"
#include "App.hpp"
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