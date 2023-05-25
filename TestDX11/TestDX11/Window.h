#pragma once
#include <Windows.h>
#include <string>
#include <optional>
#include <memory>
#include "ChiliException.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "Mouse.h"

class Window
{
public:
	class Exception : public ChiliException 
	{
	public:
		using ChiliException::ChiliException;
		static std::string TranslateErrorCode(HRESULT hr) noexcept;
	};

	class HrException : public Exception
	{
	public:
		HrException(int line, const char* file, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorDescription() const noexcept;

	private:
		HRESULT hr;
	};

	class NoGfxException : public Exception
	{
	public:
		using Exception::Exception;
		const char* GetType() const noexcept override;
	};

private:
	class WindowClass 
	{
	public:
		static const LPCSTR GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;

	private:
		WindowClass() noexcept;
		~WindowClass();

		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;

		static const LPCSTR wndClassName;
		static WindowClass wndClass;
		HINSTANCE hInst;
	};

public:
	Window(int width, int height, const char* name);
	~Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	void SetTitle(const char* title);
	static std::optional<int> ProcessMessages() noexcept;
	Graphics& Gfx();

private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

public:
	Keyboard keyboard;
	Mouse mouse;

private:
	int width;
	int height;
	HWND hWnd;
	std::unique_ptr<Graphics> pGfx;
};

// error exception helper macro
#define CHWND_EXCEPT(hr) Window::HrException(__LINE__,__FILE__,(hr))
#define CHWND_LAST_EXCEPT() Window::HrException(__LINE__,__FILE__,GetLastError())
#define GHWND_NOGFX_EXCEPT() Window::NoGfxException(__LINE__,__FILE__)