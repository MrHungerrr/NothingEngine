#pragma once


#ifdef NOTHING_ENGINE_PLATFORM_WINDOWS
	#ifdef NOTHING_ENGINE_BUILD_DLL
		#define NOTHING_ENGINE_API __declspec(dllexport)
	#else 
		#define NOTHING_ENGINE_API __declspec(dllimport)
	#endif
#else
	#error NothingEngine only on Windows!
#endif

#ifdef NOTHING_ENGINE_ENABLE_ASSERTS
	#define NE_ASSERT(x, ...) { if(!(x)) { NE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NE_CORE_ASSERT(x, ...) { if(!(x)) { NE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NE_ASSERT(x, ...)
	#define NE_CORE_ASSERT(x, ...)
#endif