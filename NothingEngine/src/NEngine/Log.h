#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


namespace NothingEngine
{
	class NOTHING_ENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


#define NE_CORE_INFO(...)   ::NothingEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NE_CORE_WARN(...)   ::NothingEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NE_CORE_ERROR(...)  ::NothingEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NE_CORE_FATAL(...)  ::NothingEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define NE_INFO(...)        ::NothingEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define NE_WARN(...)        ::NothingEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NE_ERROR(...)       ::NothingEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define NE_FATAL(...)       ::NothingEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)