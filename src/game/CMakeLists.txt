add_library(game_interface INTERFACE)
target_include_directories(game_interface INTERFACE include)

add_library(game
src/game.hpp
src/game.cpp
src/system_manager.hpp
src/system_manager.cpp
)

target_include_directories(game
	PUBLIC
		include
	PRIVATE
		src
)

target_link_libraries(game
    PUBLIC
        game_interface
    PRIVATE
        EnTT
)