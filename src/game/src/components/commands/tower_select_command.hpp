#pragma once

#include "types/entity_id.hpp"

namespace game::comp
{

struct Tower_select_command
{
    types::Entity_id selected_tower{types::Invalid_entity_id};
};

}  // namespace game::comp