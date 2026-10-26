#include <cassert>

int valor_o_cero(const int* p) {
  if (p == nullptr) return 0;
  return *p;
}

void intercambia(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  assert(valor_o_cero(nullptr) == 0);
  int x = 7;
  assert(valor_o_cero(&x) == 7);
  int y = 1, z = 2;
  intercambia(&y, &z);
  assert(y == 2 && z == 1);
  return 0;
}
