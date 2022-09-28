#pragma once

#include "entt/entt.hpp"

namespace game
{
class System_manager
{
public:
    void execute();

private:
    entt::registry registry;
};
}  // namespace game