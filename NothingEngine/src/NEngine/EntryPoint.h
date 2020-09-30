#pragma once

#ifdef NOTHING_ENGINE_PLATFORM_WINDOWS

extern NothingEngine::Application* NothingEngine::CreateApplication();

int main(int argc, char** argv)
{
	NothingEngine::Log::Init();
	NE_CORE_WARN("nihua");

	auto app = NothingEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
