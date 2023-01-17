add_library(renderer_interface INTERFACE)
target_include_directories(renderer_interface INTERFACE include)
target_link_libraries(renderer_interface
    INTERFACE
        types
)


add_library(renderer
src/hud_renderer.hpp
src/hud_renderer.cpp
src/level_renderer.hpp
src/level_renderer.cpp
src/renderer.hpp
src/renderer.cpp
src/shape_renderer.hpp
src/shape_renderer.cpp
src/sprite_cache.hpp
src/sprite_cache.cpp
src/sprite_id.cpp
src/sprite_renderer.hpp
src/sprite_renderer.cpp
src/subrenderer.hpp
src/subrenderer.cpp
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
        types
    PRIVATE
        assets
        sfml-graphics
)