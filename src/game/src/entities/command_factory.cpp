#pragma once

#include "command_factory.hpp"

#include "components/commands/tower_select_command.hpp"

namespace game::entity
{
namespace factory
{

void create_tower_select_command(entt::registry& registry, types::Entity_id entity_id)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Tower_select_command>(entity, entity_id);
}

}  // namespace factory
}  // namespace game::entity