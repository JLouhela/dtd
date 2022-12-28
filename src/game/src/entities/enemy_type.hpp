#pragma once

#include <string>
#include <unordered_map>

namespace game::entity
{

enum class Enemy_type
{
    unknown,
    basic
};

Enemy_type get_enemy_type(const std::string& enemy_type);

static const std::unordered_map<std::string, Enemy_type> ENEMY_TYPES{{"basic", Enemy_type::basic}};

}  // namespace game::entity