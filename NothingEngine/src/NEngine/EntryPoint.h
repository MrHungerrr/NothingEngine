#pragma once

#ifdef NOTHING_ENGINE_PLATFORM_WINDOWS

extern NothingEngine::Application* NothingEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = NothingEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // 
