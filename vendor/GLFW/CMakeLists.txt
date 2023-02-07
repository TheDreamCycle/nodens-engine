project(glfw)

add_library(${PROJECT_NAME} STATIC 
	"include/GLFW/glfw3.h"
	"include/GLFW/glfw3native.h"
	"src/glfw_config.h.in"
	"src/context.c"
	"src/init.c"
	"src/input.c"
	"src/monitor.c"
	"src/vulkan.c"
	"src/window.c")
		
# check if running on windows
if(WIN32)
	target_sources(${PROJECT_NAME} 
		PRIVATE 
			"src/win32_init.c"
			"src/win32_joystick.c"
			"src/win32_monitor.c"
			"src/win32_time.c"
			"src/win32_thread.c"
			"src/win32_window.c"
			"src/wgl_context.c"
			"src/egl_context.c"
			"src/osmesa_context.c")
	add_definitions(-D_GLFW_WIN32 -D_CRT_SECURE_NO_WARNINGS)
endif()