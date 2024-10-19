#include "mouse_click_system.hpp"

#include "camera/camera.hpp"
#include "components/mouse_click_component.hpp"
#include "components/position_component.hpp"
#include "components/tower_component.hpp"
#include "components/transform_component.hpp"
#include "entities/command_factory.hpp"
#include "loguru/loguru.hpp"
#include "math/rect.hpp"

namespace
{
bool handle_mouse_click_tower(entt::registry& registry, int x, int y)
{
    auto tower_view = registry.view<const game::comp::Tower, const game::comp::Position, const game::comp::Transform>();
    // use forward iterators and get only the components of interest
    for (auto entity : tower_view)
    {
        auto& pos = tower_view.get<const game::comp::Position>(entity);
        auto& transform = tower_view.get<const game::comp::Transform>(entity);

        const float width = static_cast<float>(transform.width) * transform.scale;
        const float height = static_cast<float>(transform.height) * transform.scale;
        const math::Float_rect tower_rect = {pos.x - width / 2, pos.y - height / 2, width, height};

        const auto hit = tower_rect.contains(math::Float_vector{static_cast<float>(x), static_cast<float>(y)});
        if (hit)
        {
            LOG_F(INFO, "TODO: tower select command created -> handle it");
            game::entity::factory::create_tower_select_command(registry, static_cast<types::Entity_id>(entity));
            return true;
        }
    }
    return false;
}
}  // namespace

namespace game
{

void sys::Mouse_click_system::process_mouse_click(entt::registry& reg, const Camera& camera)
{
    auto view = reg.view<const comp::Mouse_click, const comp::Position>();
    const entt::registry& creg = reg;
    for (entt::entity e : view)
    {
        const auto& mouse_click_pos = reg.get<comp::Position>(e);
        bool handled =
            handle_mouse_click_tower(reg, static_cast<int>(mouse_click_pos.x), static_cast<int>(mouse_click_pos.y));

        reg.destroy(e);
    }
}

}  // namespace game