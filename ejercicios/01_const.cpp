// M0.01 — const. LearnCpp ch. 5.1. Core Guidelines Con.1
#include <cassert>
#include <string>

// Devuelve la longitud. No copies el string. No lo mutes.
int longitud(const std::string& s) {
  (void)s;
  return 0;  // TODO: devuelve el número de caracteres de la cadena recibida por referencia constante
}

int main() {
  const std::string h = "hola";
  assert(longitud(h) == 4);
  assert(longitud(std::string{}) == 0);
  return 0;
}
