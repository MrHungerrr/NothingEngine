#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"



namespace NothingEngine
{
	class NOTHING_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
	};

	// To be defined in client
	Application* CreateApplication();
}
