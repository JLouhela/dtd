add_library(game_loop_interface INTERFACE)
target_include_directories(game_loop_interface INTERFACE include)

add_library(game_loop
    src/game_loop.hpp
    src/game_loop.cpp
)

target_include_directories(game_loop
	PUBLIC
		include
	PRIVATE
		src
)

target_link_libraries(game_loop
    PUBLIC
        game_loop_interface
    PRIVATE
        sfml-graphics
        game_interface
        renderer_interface
        loguru
)