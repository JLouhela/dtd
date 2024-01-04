#include "entity_factory.hpp"

#include "components/circle_radius_component.hpp"
#include "components/damage_component.hpp"
#include "components/direction_component.hpp"
#include "components/enemy_component.hpp"
#include "components/enemy_shooter_component.hpp"
#include "components/health_component.hpp"
#include "components/position_component.hpp"
#include "components/projectile_component.hpp"
#include "components/sound_component.hpp"
#include "components/sprite_animation_component.hpp"
#include "components/sprite_component.hpp"
#include "components/tower_component.hpp"
#include "components/transform_component.hpp"
#include "components/velocity_component.hpp"
#include "components/waypoint_follower_component.hpp"
#include "enemy_type.hpp"
#include "loguru/loguru.hpp"
#include "math/vector.hpp"
#include "renderer/sprite_id.hpp"
#include "sound_player/sound_id.hpp"

namespace
{
float get_enemy_velocity(const game::entity::Enemy_type type)
{
    switch (type)
    {
    case game::entity::Enemy_type::basic:
    {
        return 1.0f;
    }
    }
    LOG_F(WARNING, "Unhandled enemy type %d, cannot provide velocity. Using 1.0f", static_cast<uint8_t>(type));
    return 1.0f;
}
}  // namespace

namespace game::entity
{
namespace factory
{
void create_debug_entity(entt::registry& registry, float x, float y)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Position>(entity, x, y);
    registry.emplace<game::comp::Sprite>(entity, renderer::Sprite_id::Basic_tower);
    registry.emplace<game::comp::Enemy_shooter>(entity, 0.5f);
    registry.emplace<game::comp::Tower>(entity);
    registry.emplace<game::comp::Transform>(entity, std::uint8_t{40}, std::uint8_t{50}, std::uint8_t{1});
    registry.emplace<game::comp::Circle_radius>(entity, 200.0f);
}

void create_enemy(entt::registry& registry,
                  const std::string& enemy_type_str,
                  const math::Float_vector& pos,
                  const std::int8_t spawn_index,
                  const float hitpoints)
{
    auto entity = registry.create();
    const auto enemy_type = get_enemy_type(enemy_type_str);
    registry.emplace<game::comp::Position>(entity, pos.x, pos.y);
    registry.emplace<game::comp::Sprite>(entity, renderer::get_enemy_sprite(enemy_type_str));
    registry.emplace<game::comp::Direction>(entity, 0.f, 0.f);
    registry.emplace<game::comp::Enemy>(entity);
    registry.emplace<game::comp::Transform>(entity, std::uint8_t{20}, std::uint8_t{32}, std::uint8_t{1});
    registry.emplace<game::comp::Health>(entity, hitpoints, hitpoints);
    registry.emplace<game::comp::Waypoint_follower>(entity, spawn_index, std::int8_t{1});

    const auto velocity = get_enemy_velocity(enemy_type);
    registry.emplace<game::comp::Velocity>(entity, velocity);
}

void create_projectile(entt::registry& registry,
                       const types::Projectile_type& type,
                       const math::Float_vector& pos,
                       const math::Float_vector& target_pos,
                       float velocity,
                       float damage)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Position>(entity, pos.x, pos.y);
    registry.emplace<game::comp::Sprite>(entity, renderer::get_projectile_sprite(type));
    const auto dir = math::direction(pos, target_pos).normalize();
    registry.emplace<game::comp::Direction>(entity, dir.x, dir.y);
    registry.emplace<game::comp::Projectile>(entity, damage, target_pos, type);
    registry.emplace<game::comp::Velocity>(entity, velocity);
}

void create_hit(entt::registry& registry,
                const types::Projectile_type& type,
                const math::Float_vector& pos,
                const float damage,
                const float radius)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Position>(entity, pos.x, pos.y);
    const auto sound_id = sound::get_hit_sound(type);
    registry.emplace<game::comp::Sound>(entity, sound_id);
    // TODO consider separate "direct damage" with no radius, just entity id
    registry.emplace<game::comp::Damage>(entity, damage, radius);
    registry.emplace<game::comp::Sprite_animation>(
        entity,
        std::vector<renderer::Sprite_id>{renderer::Sprite_id::Basic_projectile_hit_1,
                                         renderer::Sprite_id::Basic_projectile_hit_2},
        0.5f);
}

}  // namespace factory
}  // namespace game::entity