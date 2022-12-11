add_library(game_interface INTERFACE)
target_include_directories(game_interface INTERFACE include)

add_library(game
src/constants.hpp
src/game.hpp
src/game.cpp
src/level.hpp
src/level.cpp
src/components/position_component.hpp
src/components/sprite_component.hpp
src/scenes/scene.hpp
src/scenes/scene.cpp
src/scenes/battle_scene.hpp
src/scenes/battle_scene.cpp
src/scenes/scene_id.hpp
src/scenes/menu_scene.hpp
src/scenes/menu_scene.cpp
src/scenes/scene_manager.hpp
src/scenes/scene_manager.cpp
src/systems/debug_render_system.hpp
src/systems/debug_render_system.cpp
src/systems/render_system.hpp
src/systems/render_system.cpp
src/systems/system_manager.hpp
src/systems/system_manager.cpp
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