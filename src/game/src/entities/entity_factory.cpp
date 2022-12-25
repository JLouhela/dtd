#include "entity_factory.hpp"

#include "components/position_component.hpp"
#include "components/sprite_component.hpp"

namespace game::entity
{
namespace factory
{
void create_debug_entity(entt::registry& registry)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Position>(entity, 100, 100);
    registry.emplace<game::comp::Sprite>(entity, renderer::Sprite_id::Rectangle_red);
}
}  // namespace factory
}  // namespace game::entity