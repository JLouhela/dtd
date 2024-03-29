#pragma once

#include <memory>
#include <string>

#include "../level.hpp"
#include "../systems/waypoint_follow_system.hpp"
#include "scene.hpp"
#include "systems/enemy_spawn_system.hpp"

namespace assets::level
{
class Level_interface;
}

namespace game
{
class Battle_scene : public Scene
{
public:
    Battle_scene(entt::registry& registry,
                 Camera& camera,
                 renderer::Renderer_interface& renderer,
                 sound::Sound_player_interface& sound_player,
                 input::Input_handler_interface& input_handler);

    void dispose() final;

    void init(const assets::level::Level_interface& level_content);
    void update(float delta_time) final;
    std::string get_level_id();

private:
    enum class Battle_state
    {
        // DRAFT
        BUY,
        SPAWN,

    };

    void setup_input_handler();

    void execute_renderers(float delta_time);
    void execute_sound_systems(float delta_time);

    std::shared_ptr<Level> m_level{nullptr};
    Battle_state m_state{Battle_state::BUY};
    sys::Enemy_spawn_system m_enemy_spawner;
    sys::Waypoint_follow_system m_waypoint_system;
};
}  // namespace game