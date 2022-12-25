#include "entity_factory.hpp"

#include "components/position_component.hpp"
#include "components/sprite_component.hpp"
#include "components/waypoint_follower_component.hpp"
#include "renderer/sprite_id.hpp"

namespace game::entity
{
namespace factory
{
void create_debug_entity(entt::registry& registry)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Position>(entity, 100.0f, 100.0f);
    registry.emplace<game::comp::Sprite>(entity, renderer::Sprite_id::Rectangle_red);
}

void create_enemy(entt::registry& registry, const std::string& enemy_type, const math::Float_vector& pos)
{
    auto entity = registry.create();
    registry.emplace<game::comp::Position>(entity, pos.x, pos.y);
    // TODO pick by enemy_type
    registry.emplace<game::comp::Sprite>(entity, renderer::get_enemy_sprite(enemy_type));
    // TODO create system to handle this
    registry.emplace<game::comp::Waypoint_follower>(entity, pos);
}

}  // namespace factory
}  // namespace game::entity