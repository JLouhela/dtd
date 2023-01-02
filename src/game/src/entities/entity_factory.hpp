#pragma once

#include "entt/entt.hpp"
#include "math/vector.hpp"
#include "types/projectile_type.hpp"

namespace game::entity
{
namespace factory
{
void create_debug_entity(entt::registry& registry);

void create_enemy(entt::registry& registry,
                  const std::string& enemy_type_str,
                  const math::Float_vector& pos,
                  std::int8_t spawn_index);

void create_projectile(entt::registry& registry,
                       const types::Projectile_type& type,
                       const math::Float_vector& pos,
                       const math::Float_vector& target_pos,
                       float velocity,
                       float damage);

void create_hit(const types::Projectile_type& type, const math::Float_vector& pos);

}  // namespace factory
}  // namespace game::entity