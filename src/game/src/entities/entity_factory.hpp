#pragma once
#include "entt/entt.hpp"
#include "math/vector.hpp"

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
                       const math::Float_vector& pos,
                       const math::Float_vector& target_pos,
                       float velocity);

}  // namespace factory
}  // namespace game::entity