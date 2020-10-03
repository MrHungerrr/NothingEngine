#include <NEpch.h>
#include "Application.h"


NothingEngine::Application::Application()
{
}

NothingEngine::Application::~Application()
{
}

void NothingEngine::Application::Run()
{
	WindowResizeEvent e(1280, 720);

	NE_CORE_INFO(e);

	while (true);
}
