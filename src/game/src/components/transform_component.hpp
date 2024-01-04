#pragma once

#include <cstdint>

namespace game::comp
{

struct Transform
{
    std::uint8_t width{0};
    std::uint8_t height{0};
    std::uint8_t scale{1};
};

}  // namespace game::comp