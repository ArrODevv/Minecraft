#pragma once

#ifndef MINECRAFT_VECTOR2_HPP
#define MINECRAFT_VECTOR2_HPP

#include "common.hpp"

#include <iostream>

namespace minecraft::math {
    struct Vector2 {
        float x, y;

        Vector2() : x(0.0f), y(0.0f) {}
        Vector2(float x, float y) : x(x), y(y) {}
        Vector2(float scalar) : x(scalar), y(scalar) {}

        std::string toString(uint8_t precision = 5);

        float length() const;
        float lengthSquared() const;

        void normalize();
        Vector2 normalized() const;

        float dot(const Vector2& other) const;
        // Only for 3d vectors (oopsie)
        //float cross(const Vector2& other) const;

        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        Vector2& operator*=(const Vector2& other);
        Vector2& operator/=(const Vector2& other);

        Vector2& operator+=(const float& other);
        Vector2& operator-=(const float& other);
        Vector2& operator*=(const float& other);
        Vector2& operator/=(const float& other);

        Vector2 operator-() const;
        Vector2 operator+() const;
    }; // struct Vector2

    Vector2 operator+(Vector2 left, const Vector2& right);
    Vector2 operator-(Vector2 left, const Vector2& right);
    Vector2 operator*(Vector2 left, const Vector2& right);
    Vector2 operator/(Vector2 left, const Vector2& right);

    Vector2 operator+(Vector2 left, const float& right);
    Vector2 operator-(Vector2 left, const float& right);
    Vector2 operator*(Vector2 left, const float& right);
    Vector2 operator/(Vector2 left, const float& right);

    bool operator==(const Vector2& left, const Vector2& right);
    bool operator!=(const Vector2& left, const Vector2& right);
    bool operator<(const Vector2& left, const Vector2& right);
    bool operator<=(const Vector2& left, const Vector2& right);
    bool operator>(const Vector2& left, const Vector2& right);
    bool operator>=(const Vector2& left, const Vector2& right);

    std::ostream& operator<<(std::ostream& os, Vector2& v);
} // namespace minecraft::math

#endif // !MINECRAFT_VECTOR2_HPP
