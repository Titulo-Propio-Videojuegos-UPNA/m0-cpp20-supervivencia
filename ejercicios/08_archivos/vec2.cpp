#include "vec2.h"

Vec2::Vec2(float x_, float y_) : x(x_), y(y_) {}

Vec2 Vec2::operator+(const Vec2& o) const {
  (void)o;
  return {};  // TODO: devuelve un nuevo Vec2 con la suma componente a componente
}

float Vec2::length_sq() const {
  return 0.f;  // TODO: devuelve la magnitud al cuadrado del vector (sin usar sqrt)
}
