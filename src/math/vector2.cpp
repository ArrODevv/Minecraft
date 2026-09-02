#include "vector2.hpp"
#include "mmath.hpp"

#include <sstream>

namespace minecraft::math {
    std::string Vector2::toString(uint8_t precision) {
        std::ostringstream ss;
        ss.precision(precision);
        ss << "Vector2(" << x << ", " << y << ")";
        return ss.str();
    }

    float Vector2::length() const {
        return sqrt(x * x + y * y);
    }

    float Vector2::lengthSquared() const {
        return x * x + y * y;
    }

    void Vector2::normalize() {
        float len = this->length();

        // NOTE: use EPSILON?
        if(len != 0.0f) {
            x /= len;
            y /= len;
        } else {
            x = 0.0f;
            y = 0.0f;
        }
    }

    Vector2 Vector2::normalized() const {
        float len = this->length();

        if(len != 0.0f) {
            return Vector2(x / len, y / len);
        }

        return Vector2();
    }

    float Vector2::dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    // Only for 3d vectors (oopsie)
    //float Vector2::cross(const Vector2& other) const {
    //    // I hope this formula is correct: (from https://wumbo.net/formulas/cross-product-2d/)
    //    return (x * other.y) - (y * other.x);
    //}

    Vector2& Vector2::operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2& Vector2::operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2& Vector2::operator*=(const Vector2& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vector2& Vector2::operator/=(const Vector2& other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vector2& Vector2::operator+=(const float& other) {
        x += other;
        y += other;
        return *this;
    }

    Vector2& Vector2::operator-=(const float& other) {
        x -= other;
        y -= other;
        return *this;
    }

    Vector2& Vector2::operator*=(const float& other) {
        x *= other;
        y *= other;
        return *this;
    }

    Vector2& Vector2::operator/=(const float& other) {
        x /= other;
        y /= other;
        return *this;
    }

    Vector2 Vector2::operator-() const {
        return Vector2(-x, -y);
    }

    Vector2 Vector2::operator+() const {
        return Vector2(+x, +y);
    }

    Vector2 operator+(Vector2 left, const Vector2& right) {
        left += right;
        return left;
    }

    Vector2 operator-(Vector2 left, const Vector2& right) {
        left -= right;
        return left;
    }

    Vector2 operator*(Vector2 left, const Vector2& right) {
        left *= right;
        return left;
    }

    Vector2 operator/(Vector2 left, const Vector2& right) {
        left /= right;
        return left;
    }

    Vector2 operator+(Vector2 left, const float& right) {
        left += right;
        return left;
    }

    Vector2 operator-(Vector2 left, const float& right) {
        left -= right;
        return left;
    }

    Vector2 operator*(Vector2 left, const float& right) {
        left *= right;
        return left;
    }

    Vector2 operator/(Vector2 left, const float& right) {
        left /= right;
        return left;
    }

    bool operator==(const Vector2& left, const Vector2& right) {
        // NOTE: is this correct?
        return (abs(right.x - left.x) < EPSILON) && (abs(right.y - left.y) < EPSILON);
    }

    bool operator!=(const Vector2& left, const Vector2& right) {
        return !(left == right);
    }

    bool operator<(const Vector2& left, const Vector2& right) {
        return (left.x < right.x) && (left.y < right.y);
    }

    bool operator<=(const Vector2& left, const Vector2& right) {
        return !(left > right);
    }

    bool operator>(const Vector2& left, const Vector2& right) {
        return right < left;
    }

    bool operator>=(const Vector2& left, const Vector2& right) {
        return right <= left;
    }

    std::ostream& operator<<(std::ostream& os, Vector2& v) {
        os.precision(5);
        os << "Vector2(" << v.x << ", " << v.y << ")";
        return os;
    }
} // namespace minecraft::math
