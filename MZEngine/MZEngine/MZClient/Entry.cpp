// MZClient.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Entry.h"
#include "Client.h"
#include "../MZEngine/IMZEngine.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
UINT screenWidth = 1920;
UINT screenHeight = 1080;
HWND hWnd;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
void				ChangeResolution();
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MZCLIENT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	ChangeResolution();

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	
	// Engine Initialize
	IMZEngine* engine = CreateEngine();
	engine->Initialize(hWnd, screenWidth, screenHeight);

	// Client Initialize
	Client* client = new Client();
	client->Initialize();

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MZCLIENT));

	MSG msg;

	// Main message loop:
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			DispatchMessage(&msg);
		}
		else
		{
			// Engine Loop
			engine->Run();
		}
	}

	// Engine Finalize
	engine->Finalize();
	ReleaseEngine(engine);

	UnregisterClass(szWindowClass, hInstance);
	return 0;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MZCLIENT));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MZCLIENT);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//	FUNCTION: ChangeResolution()
//
//	PURPOSE: Change resolution before create main window
//
void ChangeResolution()
{
	// change resolution depending on display settings
	DEVMODE dmSettings;
	memset(&dmSettings, 0, sizeof(dmSettings));
	if (!EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dmSettings))
	{
		MessageBox(NULL, L"Could Not Enum Display Settings", L"Error", MB_OK);
		PostQuitMessage(0);
	}

	int result = ChangeDisplaySettings(&dmSettings, CDS_FULLSCREEN);
	if (result != DISP_CHANGE_SUCCESSFUL)
	{
		MessageBox(NULL, L"Display Mode Not Compatible", L"Error", MB_OK);
		PostQuitMessage(0);
	}

	screenWidth = dmSettings.dmPelsWidth;
	screenHeight = dmSettings.dmPelsHeight;
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	// for windowed mode
	hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		0, 0, screenWidth, screenHeight, nullptr, nullptr, hInstance, nullptr);

	// for full screen mode
	/*hWnd = CreateWindowW(szWindowClass, szTitle, WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
				0, 0, screenWidth, screenHeight, nullptr, nullptr, hInstance, nullptr);*/

	if (!hWnd)
	{
		return FALSE;
	}

	SetMenu(hWnd, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

