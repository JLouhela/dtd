add_library(game_interface INTERFACE)
target_include_directories(game_interface INTERFACE include)

add_library(game
src/game.hpp
src/game.cpp
src/level.hpp
src/level.cpp
src/system_manager.hpp
src/system_manager.cpp
src/scenes/scene.hpp
src/scenes/scene.cpp
src/scenes/battle_scene.hpp
src/scenes/battle_scene.cpp
src/scenes/scene_id.hpp
src/scenes/menu_scene.hpp
src/scenes/menu_scene.cpp
src/scenes/scene_manager.hpp
src/scenes/scene_manager.cpp
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
        renderer_interface
        EnTT
)