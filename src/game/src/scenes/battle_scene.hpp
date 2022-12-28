#pragma once

#include <string>

#include "level.hpp"
#include "scene.hpp"
#include "systems/enemy_spawn_system.hpp"

namespace game
{
class Battle_scene : public Scene
{
public:
    Battle_scene(entt::registry& registry, renderer::Renderer_interface& renderer);

    void dispose() final;

    void init(const Level& level);
    void update(std::int32_t delta_time) final;
    std::string get_level_id();

private:
    enum class Battle_state
    {
        // DRAFT
        BUY,
        SPAWN,

    };

    void execute_renderers();
    const Level* m_level{nullptr};
    Battle_state m_state{Battle_state::BUY};
    sys::Enemy_spawn_system m_enemy_spawner;
};
}  // namespace game