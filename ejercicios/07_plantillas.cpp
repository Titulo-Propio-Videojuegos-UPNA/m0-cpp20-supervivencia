// M0.07 — function template mínima. LearnCpp ch. 11
#include <cassert>
#include <string>

template <typename T>
T mayor(T a, T b) {
  (void)b;
  return a;  // TODO: compara ambos valores del tipo genérico T y devuelve el mayor
}

int main() {
  assert(mayor(2, 9) == 9);
  assert(mayor(3.0, 1.5) == 3.0);
  assert(mayor(std::string{"aa"}, std::string{"b"}) == "b");
  return 0;
}
