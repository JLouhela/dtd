add_library(renderer_interface INTERFACE)
target_include_directories(renderer_interface INTERFACE include)

add_library(renderer
src/debug_renderer.hpp
src/debug_renderer.cpp
src/renderer.hpp
src/renderer.cpp
src/sprite_renderer.hpp
src/sprite_renderer.cpp
src/window_size.hpp
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