#pragma once

#include "entt/entt.hpp"
#include "math/vector.hpp"
#include "types/projectile_type.hpp"

namespace game::entity
{
namespace factory
{
void create_debug_entity(entt::registry& registry, float x, float y);

void create_enemy(entt::registry& registry,
                  const std::string& enemy_type_str,
                  const math::Float_vector& pos,
                  std::int8_t spawn_index,
                  float hitpoints);

void create_mouse_click(entt::registry& registry, int x, int y);

void create_projectile(entt::registry& registry,
                       const types::Projectile_type& type,
                       const math::Float_vector& pos,
                       const math::Float_vector& target_pos,
                       float velocity,
                       float damage);

void create_hit(entt::registry& registry,
                const types::Projectile_type& type,
                const math::Float_vector& pos,
                float damage,
                float radius);

}  // namespace factory
}  // namespace game::entity