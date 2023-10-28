#include "include/resource.h"
#include "include/window.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

Window::Window()
{
	// Register window class
	const char CLASS_NAME[] = "SDNX Window Class";

	WNDCLASSEX wndClass    = {};
	wndClass.cbSize        = sizeof(WNDCLASSEX);
	wndClass.style         = 0;
	wndClass.cbClsExtra    = 0;
	wndClass.cbWndExtra    = 0;
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance     = m_hInstance;
	wndClass.hIcon         = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_SDNX_32));
	wndClass.hIconSm       = (HICON)LoadImage(m_hInstance, MAKEINTRESOURCE(IDI_SDNX_32), IMAGE_ICON, 16, 16, 0);
	wndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.lpfnWndProc   = WindowProc;

	if (!RegisterClassEx(&wndClass))
	{
		MessageBox(NULL, "Window registration failed!", "Error!", MB_ICONERROR | MB_OK);
	}

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	int width  = 325;
	int height = 500;

	RECT rect{};
	rect.left   = 250;
	rect.top    = 250;
	rect.right  = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	// Create the window
	m_hWnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,    // Optional window styles
		CLASS_NAME,          // Window class
		"SDNX",              // Window title
		WS_OVERLAPPEDWINDOW, // Window style
		
		// Size and position
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,

		NULL,        // Parent window
		NULL,        // Menu
		m_hInstance, // Instance handle
		NULL         // Additional application data
	);

	if (m_hWnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONERROR | MB_OK);
	}

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
}

Window::~Window()
{
	const LPCSTR CLASS_NAME = "SDNX Window Class";

	UnregisterClass(CLASS_NAME, m_hInstance);
}

bool Window::ProcessMessages()
{
	MSG msg = {};

	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return false;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}