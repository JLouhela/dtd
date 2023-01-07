#include "enemy_type.hpp"

#include "loguru/loguru.hpp"

namespace game::entity
{

Enemy_type get_enemy_type(const std::string& enemy_type)
{
    const auto it = ENEMY_TYPES.find(enemy_type);
    if (it != ENEMY_TYPES.end())
    {
        return it->second;
    }
    LOG_F(WARNING, "Enemy type %s does not exist / mapping missing!", enemy_type.c_str());
    return Enemy_type::unknown;
}

}