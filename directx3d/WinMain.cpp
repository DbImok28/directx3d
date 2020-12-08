#include <Windows.h>
#include <exception>
#include <sstream>
#include "WindowsMessageMap.hpp"
#include "App.hpp"
#include "EngineException.hpp"


int CALLBACK WinMain(
								// CALLBACK #define ��� stdcall(���������� ��� �������, ���������� ������ ����� ��� �� ����� ������� ����)
	_In_ HINSTANCE	hInstance,		// ��������� �� ������ ������������ ������, �� ���������
	_In_opt_ HINSTANCE	hPrevInstance,	// ��� 16 ������ ������
	_In_ LPSTR		lpCmdLine,		// �������
	_In_ int			nCmdShow)		// �������� ���������� �� �� ��� ����� ������������ ���� (�������, ���������, �� ���� ����� � �.�.).
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