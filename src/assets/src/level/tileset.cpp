#include "assets/level/tileset.hpp"

namespace assets
{
namespace level
{
std::uint32_t Tileset::has_tile(const std::uint32_t id)
{
    return id >= m_first_gid && id <= m_last_gid;
}
}  // namespace level
}  // namespace assets