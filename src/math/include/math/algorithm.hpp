#pragma once

#include <cmath>
#include <cstdint>
#include <limits>

namespace math
{

inline bool float_eq(float x, float y, float epsilon)
{
    return std::fabs(x - y) <= epsilon;
}
inline bool float_eq(float x, float y)
{
    return float_eq(x, y, std::numeric_limits<float>::epsilon());
}

inline bool double_eq(double x, double y, double epsilon)
{
    return std::fabs(x - y) <= epsilon;
}
inline bool double_eq(double x, double y)
{
    return double_eq(x, y, std::numeric_limits<double>::epsilon());
}

}  // namespace math