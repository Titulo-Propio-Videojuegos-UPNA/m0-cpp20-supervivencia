// M0.02 — pass by const ref. LearnCpp ch. 12. Core Guidelines F.16
#include <cassert>
#include <vector>

void escala(std::vector<int>& v, int k) {
  (void)v;
  (void)k;
  // TODO: multiplica cada elemento del vector in-place por el factor k
}

int suma(const std::vector<int>& v) {
  (void)v;
  return 0;  // TODO: acumula y devuelve la suma de los elementos sin copiar el vector
}

int main() {
  std::vector<int> v{1, 2, 3};
  escala(v, 10);
  assert((v == std::vector<int>{10, 20, 30}));
  assert(suma(v) == 60);
  return 0;
}
