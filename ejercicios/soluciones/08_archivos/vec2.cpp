#include "vec2.h"

Vec2::Vec2(float x_, float y_) : x(x_), y(y_) {}

Vec2 Vec2::operator+(const Vec2& o) const { return Vec2{x + o.x, y + o.y}; }

float Vec2::length_sq() const { return x * x + y * y; }
