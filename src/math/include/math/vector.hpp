#pragma once

#include <cmath>
#include <cstdint>

#include "default_values.hpp"

namespace math
{

template <typename T>
struct Vector
{
    T x{default_value<T>};
    T y{default_value<T>};

    T length()
    {
        return static_cast<T>(std::sqrt(std::pow(x, 2) + std::pow(y, 2)));
    }

    Vector normalize()
    {
        const auto len = length();
        return {x / len, y / len};
    }
};

using Int_vector = Vector<std::int32_t>;
using UInt_vector = Vector<std::uint32_t>;
using Double_vector = Vector<double>;
using Float_vector = Vector<float>;

template <typename T>
[[nodiscard]] constexpr Vector<T> operator+(const Vector<T>& left, const Vector<T>& right)
{
    return Vector<T>{left.x + right.x, left.y + right.y};
}

template <typename T>
[[nodiscard]] constexpr Vector<T> operator-(const Vector<T>& left, const Vector<T>& right)
{
    return Vector<T>{left.x - right.x, left.y - right.y};
}

template <typename T>
[[nodiscard]] constexpr Vector<T> operator*(const Vector<T>& left, const Vector<T>& right)
{
    return Vector<T>{left.x * right.x, left.y * right.y};
}

template <typename T>
[[nodiscard]] constexpr Vector<T> operator/(const Vector<T>& left, const Vector<T>& right)
{
    return Vector<T>{left.x / right.x, left.y / right.y};
}

template <typename T>
constexpr Vector<T>& operator+=(Vector<T>& left, const Vector<T>& right)
{
    left.x += right.x;
    left.y += right.y;

    return left;
}

template <typename T>
constexpr Vector<T>& operator-=(Vector<T>& left, const Vector<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;

    return left;
}

template <typename T>
constexpr Vector<T>& operator*=(Vector<T>& left, const Vector<T>& right)
{
    left.x *= right.x;
    left.y *= right.y;

    return left;
}

template <typename T>
constexpr Vector<T>& operator/=(Vector<T>& left, const Vector<T>& right)
{
    left.x /= right.x;
    left.y /= right.y;

    return left;
}

template <typename T>
constexpr bool operator==(const Vector<T>& left, const Vector<T>& right)
{
    return (left.x == right.x) && (left.y == right.y);
}

template <typename T>
constexpr bool operator!=(const Vector<T>& left, const Vector<T>& right)
{
    return (left.x != right.x) || (left.y != right.y);
}

template <typename T>
T direction(const T& lhs, const T& rhs)
{
    return {rhs.x - lhs.x, rhs.y - lhs.y};
}

}  // namespace math