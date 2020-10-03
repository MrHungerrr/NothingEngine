#pragma once


#include "NEngine/Window.h"
#include <GLFW/glfw3.h>


namespace NothingEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void Update() override;

		inline uint32_t GetWidth() const override { return m_Data.Width; }
		inline uint32_t GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(const bool option) override;
		bool IsVSync() const override;

	private:
		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		GLFWwindow* m_Window;
		WindowData m_Data;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	};


}