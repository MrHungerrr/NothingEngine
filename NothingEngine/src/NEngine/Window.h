#pragma once

#include <NEpch.h>
#include "NEngine\Core.h"
#include "NEngine\Events\Event.h"

namespace NothingEngine
{
	
	struct NOTHING_ENGINE_API WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Nothing Engine", 
			const uint32_t width = 1280, 
			const uint32_t height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};



	class NOTHING_ENGINE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		virtual void Update() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(const bool option) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};



}