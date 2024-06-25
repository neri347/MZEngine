#pragma once
#include <windows.h>

/// MZEngine�� �������̽�
/// Ŭ���̾�Ʈ���� �������̽��� �����͸� ����
/// ������ �Լ����� �����Ų��.

class IMZEngine abstract
{
public:
	virtual ~IMZEngine() {};
	virtual void Initialize(HWND hWnd, UINT screenWidth, UINT screenHeight) = 0;
	virtual void Run() = 0;
	virtual void Finalize() = 0;
};

__declspec(dllexport) IMZEngine* CreateEngine();
__declspec(dllexport) void ReleaseEngine(IMZEngine* engine);