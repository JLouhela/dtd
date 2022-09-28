add_library(renderer_interface INTERFACE)
target_include_directories(renderer_interface INTERFACE include)

add_library(renderer
    src/renderer.hpp
    src/renderer.cpp
)

target_include_directories(renderer
	PUBLIC
		include
	PRIVATE
		src
)

target_link_libraries(renderer
    PUBLIC
        renderer_interface
        sfml-window
    PRIVATE
        sfml-graphics
)