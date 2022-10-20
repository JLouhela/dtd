#include "battle_scene.hpp"

namespace game
{
void Battle_scene::init(const std::string& level)
{
    m_level.load(level);
}

}  // namespace game