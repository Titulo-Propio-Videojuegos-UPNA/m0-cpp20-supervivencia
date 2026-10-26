// M0.08 — varios .cpp + std::vector. LearnCpp ch. 2.8, 16
#include "vec2.h"

#include <cassert>
#include <vector>

int main() {
  std::vector<Vec2> pts;
  pts.push_back(Vec2{3.f, 4.f});
  pts.push_back(Vec2{0.f, 0.f});
  const Vec2 s = pts[0] + Vec2{1.f, 1.f};
  assert(s.x == 4.f && s.y == 5.f);
  assert(pts[0].length_sq() == 25.f);
  assert(pts.size() == 2);
  return 0;
}
