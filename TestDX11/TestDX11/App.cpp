#include "App.h"
#include <sstream>
#include <string>
#include <iomanip>

App::App()
	: wnd(800, 600, "The Donkey Fart Box") {}

int App::Go()
{
	MSG msg;
	BOOL gResult;

	/**************************************************************************************
	
	// if not get message, the loop will not be excuted;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		// translate message will post auxilliary WM_CHAR messages from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
	}

	// check if GetMessage call itself borked
	if (gResult == -1) {
		throw CHWND_LAST_EXCEPT();
	}
	else {
		// wParam here is the value passed to PostQuitMessage
		return msg.wParam;
	}

	**************************************************************************************/

	while (true)
	{
		// process all message pending, but to not block for new message
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	// test keyboard input system
	//if (wnd.keyboard.KeyIsPressed(VK_MENU))
	//{
	//	MessageBox(nullptr, "Something Happen!", "Space Key was pressed", MB_OK | MB_ICONEXCLAMATION);
	//}

	// test mouse input system
	//while (!wnd.mouse.IsEmpty()) {
	//	const auto e = wnd.mouse.Read();
	//	if (e.GetType() == Mouse::Event::Type::Move) {
	//		std::ostringstream oss;
	//		oss << "Mouse Position:(" << e.GetPosX() << "," << e.GetPosY() << ")";
	//		wnd.SetTitle(oss.str().c_str());
	//	}
	//}

	// test mouse enter leave
	//while (!wnd.mouse.IsEmpty()) {
	//	const auto e = wnd.mouse.Read();
	//	switch (e.GetType()) {
	//	case Mouse::Event::Type::Leave:
	//		wnd.SetTitle("Gone!");
	//		break;
	//	case Mouse::Event::Type::Enter:
	//	{
	//		std::ostringstream oss;
	//		oss << "Mouse move to(" << e.GetPosX() << "," << e.GetPosY() << ")";
	//		wnd.SetTitle(oss.str().c_str());
	//	}
	//	break;
	//	}
	//}

	// test wheel delta
	//static int i = 0;
	//while (!wnd.mouse.IsEmpty()) {
	//	const auto e = wnd.mouse.Read();
	//	switch (e.GetType())
	//	{
	//	case Mouse::Event::Type::WheelUp:
	//	{
	//		++i;
	//		std::ostringstream oss;
	//		oss << "Up: " << i;
	//		wnd.SetTitle(oss.str().c_str());
	//	}
	//	break;
	//	case Mouse::Event::Type::WheelDown:
	//	{
	//		--i;
	//		std::ostringstream oss;
	//		oss << "Down: " << i;
	//		wnd.SetTitle(oss.str().c_str());
	//	}
	//	break;
	//	default:
	//		break;
	//	}
	//}

	//std::ostringstream oss;
	//oss << "Time elapsed: " << std::setprecision(1) << std::fixed << tc.getSecond() << "s";
	//wnd.SetTitle(oss.str().c_str());

	while (const auto e = wnd.mouse.Read())
	{
		switch (e->GetType())
		{
		case Mouse::Event::Type::Move:
		{
			std::ostringstream oss;
			oss << "Mouse move to: (" << e->GetPosX() << "," << e->GetPosY() << ")\n";
			wnd.SetTitle(oss.str().c_str());
			break;
		}
		}
	}

	const float c = sin(tc.getSecond()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	//wnd.Gfx().DrawTestTriangle(tc.getSecond());
	wnd.Gfx().DrawTestTriangle(tc.getSecond(),
		wnd.mouse.GetPosX() / 400.0f - 1.0f,
		-wnd.mouse.GetPosY() / 300.0f + 1.0f);
	wnd.Gfx().EndFrame();
}
