#pragma once

#include <types/entity_id.hpp>

#include "entt/entt.hpp"

namespace game::entity
{
namespace factory
{

void create_tower_select_command(entt::registry& registry, types::Entity_id entity_id);

}  // namespace factory
}  // namespace game::entity