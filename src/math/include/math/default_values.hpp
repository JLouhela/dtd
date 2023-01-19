#pragma once

#include <cmath>
#include <cstdint>

namespace math
{

template <class T>
constexpr T default_value = {};

template <>
constexpr double default_value<double> = 0.0;
template <>
constexpr std::int32_t default_value<std::int32_t> = 0;
template <>
constexpr std::uint32_t default_value<std::uint32_t> = 0;

}  // namespace math