solution "ECS"
	configurations { "Debug", "Release" }
	location "build/"
	
	project "ECS"
		kind "ConsoleApp"
		language "C++"
		files { "src/**.cpp" }
		includedirs { "include", "include/**" }
		links { "sfml-graphics", "sfml-window", "sfml-system" }
		location "build/"
		buildoptions "-std=c++11"

		configuration "Debug"
			flags { "ExtraWarnings", "FatalWarnings" }

		configuration "Release"
			flags { "Optimize" }
