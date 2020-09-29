#include <NothingEngine.h>

class Sandbox : public NothingEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};


NothingEngine::Application* NothingEngine::CreateApplication()
{
	return new Sandbox();
}
