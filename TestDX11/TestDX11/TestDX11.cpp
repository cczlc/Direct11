#include <Windows.h>
#include "App.h"

//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
//	static WindowMessageMap mm;
//
//	switch (msg) {
//	case WM_CLOSE:
//	// the 69 is set to be wParam
//		PostQuitMessage(69);	// send process quit message to message queue
//		break;
//	// 可以处理非文本字符，不区分大小写
//	case WM_KEYDOWN:
//		if(wParam == 'F') {
//			SetWindowText(hWnd, L"Respect!");
//		}
//		break;
//	case WM_KEYUP:
//		if (wParam == 'F') {
//			SetWindowText(hWnd, L"Dangerfield");
//		}
//		break;
//	// 处理文本字符，区分大小写
//	case WM_CHAR: 
//	{
//		static std::wstring title;
//		title.push_back((char)wParam);
//		SetWindowText(hWnd, title.c_str());
//	}
//		break;
//	// 处理鼠标左键按下
//	case WM_LBUTTONDOWN:
//	{
//		const POINTS pt = MAKEPOINTS(lParam);
//		std::wostringstream oss;
//		oss << "(" << pt.x << ", " << pt.y << ")";
//		SetWindowText(hWnd, oss.str().c_str());
//	}
//		break;
//	}
//
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) 
{
	try
	{
		return App{}.Go();
	}
	catch (const ChiliException& e) {
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e) {
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}

}