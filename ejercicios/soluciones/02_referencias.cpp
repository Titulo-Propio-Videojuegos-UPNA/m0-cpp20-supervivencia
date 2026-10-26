#include <cassert>
#include <vector>

void escala(std::vector<int>& v, int k) {
  for (int& x : v) x *= k;
}

int suma(const std::vector<int>& v) {
  int acc = 0;
  for (int x : v) acc += x;
  return acc;
}

int main() {
  std::vector<int> v{1, 2, 3};
  escala(v, 10);
  assert((v == std::vector<int>{10, 20, 30}));
  assert(suma(v) == 60);
  return 0;
}
