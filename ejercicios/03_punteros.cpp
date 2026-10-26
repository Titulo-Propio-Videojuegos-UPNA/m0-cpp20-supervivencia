// M0.03 — punteros. LearnCpp ch. 12. nullptr, no new.
#include <cassert>

int valor_o_cero(const int* p) {
  (void)p;
  return -1;  // TODO: devuelve el entero apuntado, o 0 si el puntero es nulo
}

void intercambia(int* a, int* b) {
  (void)a;
  (void)b;
  // TODO: intercambia los valores almacenados en las dos direcciones recibidas
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
