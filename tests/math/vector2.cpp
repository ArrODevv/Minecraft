#include "math/vector2.hpp"

#include <gtest/gtest.h>

#define COMMON_D                        \
    using namespace minecraft::math;    \
    Vector2 v { 123.0f, 123.0f };       \

TEST(Vector2, Creation) {
    COMMON_D;
    ASSERT_FLOAT_EQ(v.x, 123.0f);
    ASSERT_FLOAT_EQ(v.y, 123.0f);
}

TEST(Vector2, ToString) {
    COMMON_D;
    std::string vStr = v.toString();
    ASSERT_STRCASEEQ(vStr.c_str(), "Vector2(123, 123)");
}

TEST(Vector2, Lengths) {
    COMMON_D;
    ASSERT_FLOAT_EQ(v.length(), 173.94827f); // len(v) = 173.94826817189069100260771307779
    ASSERT_FLOAT_EQ(v.lengthSquared(), 30258.0f); // Sqlen(v) = 30258
}

TEST(Vector2, Normalization) {
    COMMON_D;
    Vector2 shouldBe { 0.70711, 0.70711 }; // norm(v) = (0.70710678118654752440084436210486)
    ASSERT_EQ(v.normalized(), shouldBe) << "Vector2 \"copy\" normalization failed"; // Vector2-copy

    v.normalize();
    ASSERT_EQ(v, shouldBe) << "Vector2 \"in-place\" normalization failed"; // in-place
}

TEST(Vector2, Dot) {
    COMMON_D;
    Vector2 second { 123.0f, 123.0f };
    ASSERT_EQ(v.dot(second), 30258.0f);
}

TEST(Vector2, DotSameAsSqrLen) {
    COMMON_D;
    Vector2 second { 123.0f, 123.0f };
    ASSERT_EQ(v.dot(second), v.lengthSquared());
}
