workspace "B2D-Sandbox"
	cppdialect "C++17"
	systemversion "latest"

	startproject "Sandbox"

	targetdir "Bin/%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"
	objdir "Tmp/%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}/%{prj.name}"

	flags { "MultiProcessorCompile" }

	configurations
	{
		"Debug",
		"Release"
	}

	platforms
	{
		"Win32",
		"Win64"
	}
	
	filter "configurations:Debug"
		symbols "On"
		optimize "Off"

	filter "configurations:Release"
		symbols "Off"
		optimize "On"

	filter "platforms:Win32"
		system "Windows"
		architecture "x86"

	filter "platforms:Win64"
		system "Windows"
		architecture "x64"
	
	include "B2D"

project "Sandbox"
	location "Sandbox"
	language "C++"
	kind "ConsoleApp"
	staticruntime "On"

	files
	{
		"%{prj.location}/Source/**"
	}

	includedirs
	{
		"B2D/Source/",
		"B2D/Libraries/glm/",
		"B2D/Libraries/spdlog/include/"
	}

	links
	{
		"B2D"
	}

	filter "system:windows"
		buildoptions ("/sdl")
