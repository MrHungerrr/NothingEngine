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