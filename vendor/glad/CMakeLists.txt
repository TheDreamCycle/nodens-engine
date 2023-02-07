# glad library
project(glad)

include_directories("include")

add_library(${PROJECT_NAME} 
	"include/glad/glad.h"
	"include/KHR/khrplatform.h"
	"src/glad.c"
)

find_package(OpenGL REQUIRED)
