workspace "B2D-Sandbox"
	startproject "Sandbox"
	include "B2D"

project "Sandbox"
	location "Sandbox"
	language "C++"
	kind "ConsoleApp"

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
