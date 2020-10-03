#include <NEpch.h>
#include "Application.h"

#include <GLFW/glfw3.h>


NothingEngine::Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());
}

NothingEngine::Application::~Application()
{
}

void NothingEngine::Application::Run()
{
	while (m_IsRunning)
	{
		m_Window->Update();
	}
}
