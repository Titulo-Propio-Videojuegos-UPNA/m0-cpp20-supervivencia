#pragma once

struct Vec2 {
  float x = 0.f;
  float y = 0.f;

  Vec2() = default;
  Vec2(float x_, float y_);

  Vec2 operator+(const Vec2& o) const;
  float length_sq() const;
};
