project(implot)

add_library(implot STATIC 
	"implot.cpp"	
	"implot.h"
	"implot_internal.h"
	"implot_items.cpp"
	"implot_demo.cpp"
)

target_include_directories(implot PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(implot PUBLIC imgui)
