#pragma once

#include <cstdint>
#include <limits>

namespace types
{
using Entity_id = std::uint32_t;
static const Entity_id Invalid_entity_id{std::numeric_limits<std::uint32_t>::max()};

}  // namespace types