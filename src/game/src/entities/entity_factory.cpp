#include "entity_factory.hpp"

#include "components/circle_radius_component.hpp"
#include "components/direction_component.hpp"
#include "components/enemy_shooter_component.hpp"
#include "components/position_component.hpp"
#include "components/speed_component.hpp"
#include "components/sprite_component.hpp"
#include "components/waypoint_follower_component.hpp"
#include "enemy_type.hpp"
#include "loguru/loguru.hpp"
#include "renderer/sprite_id.hpp"

namespace
{
float get_enemy_speed(const game::entity::Enemy_type type)
{
    switch (type)
    {
    case game::entity::Enemy_type::basic:
    {
        return 1.0f;
    }
    }
    LOG_F(WARNING, "Unhandled enemy type %d, cannot provide speed. Using 1.0f", static_cast<uint8_t>(type));
    return 1.0f;
}
}  // namespace

namespace game::entity
{
namespace factory
{
void create_debug_entity(entt::registry& registry)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Position>(entity, 608.0f, 544.0f);
    registry.emplace<game::comp::Sprite>(entity, renderer::Sprite_id::Basic_tower);
    registry.emplace<game::comp::Enemy_shooter>(entity, 1.0f);
    registry.emplace<game::comp::Circle_radius>(entity, 200.0f);
}

void create_enemy(entt::registry& registry,
                  const std::string& enemy_type_str,
                  const math::Float_vector& pos,
                  const std::int8_t spawn_index)
{
    auto entity = registry.create();
    const auto enemy_type = get_enemy_type(enemy_type_str);
    registry.emplace<game::comp::Position>(entity, pos.x, pos.y);
    registry.emplace<game::comp::Sprite>(entity, renderer::get_enemy_sprite(enemy_type_str));
    registry.emplace<game::comp::Direction>(entity, 0.f, 0.f);
    registry.emplace<game::comp::Waypoint_follower>(entity, spawn_index, std::int8_t{1});

    const auto speed = get_enemy_speed(enemy_type);
    registry.emplace<game::comp::Speed>(entity, speed);
}

}  // namespace factory
}  // namespace game::entity