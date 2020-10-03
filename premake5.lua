workspace "NothingEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "NothingEngine/vendor/GLFW/include"

include "NothingEngine/vendor/GLFW"

project "NothingEngine"
    location "NothingEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

    pchheader "NEpch.h"
    pchsource "%{prj.name}/src/NEpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
            "GLFW",
            "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
        defines
        {
            "NOTHING_ENGINE_BUILD_DLL",
            "NOTHING_ENGINE_PLATFORM_WINDOWS"
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines
        {
            "NOTHING_ENGINE_DEBUG",
            "NOTHING_ENGINE_ENABLE_ASSERTS"
        }
        symbols "On"

    filter "configurations:Release"
        defines "NOTHING_ENGINE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NOTHING_ENGINE_DIST"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin_int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "NothingEngine/vendor/spdlog/include",
        "NothingEngine/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
        defines
        {
            "NOTHING_ENGINE_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines
            {
                "NOTHING_ENGINE_ENABLE_ASSERTS"
            }

    links
    {
        "NothingEngine"
    }

    filter "configurations:Debug"
        defines "NOTHING_ENGINE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NOTHING_ENGINE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NOTHING_ENGINE_DIST"
        optimize "On"