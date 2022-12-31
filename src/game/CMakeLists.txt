add_library(game_interface INTERFACE)
target_include_directories(game_interface INTERFACE include)

add_library(game
src/constants.hpp
src/game.hpp
src/game.cpp
src/level.hpp
src/level.cpp
src/components/circle_radius_component.hpp
src/components/direction_component.hpp
src/components/enemy_shooter_component.hpp
src/components/position_component.hpp
src/components/sprite_component.hpp
src/components/waypoint_follower_component.hpp
src/entities/enemy_type.hpp
src/entities/enemy_type.cpp
src/entities/entity_factory.hpp
src/entities/entity_factory.cpp
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
src/systems/enemy_spawn_system.hpp
src/systems/enemy_spawn_system.cpp
src/systems/movement_system.hpp
src/systems/movement_system.cpp
src/systems/render_system.hpp
src/systems/render_system.cpp
src/systems/waypoint_follow_system.hpp
src/systems/waypoint_follow_system.cpp
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
        assets_interface
        renderer_interface
        EnTT
)