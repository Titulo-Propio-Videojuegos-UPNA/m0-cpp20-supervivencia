// M0.04 — RAII. LearnCpp ch. 22. Core Guidelines R.1, R.11
// Prohibido new/delete en este archivo.
#include <cassert>
#include <memory>
#include <string>

struct Recurso {
  explicit Recurso(std::string n) : nombre(std::move(n)) {}
  std::string nombre;
};

std::unique_ptr<Recurso> fabrica(const std::string& nombre) {
  (void)nombre;
  return nullptr;  // TODO: construye y devuelve el Recurso gestionado por puntero único (sin usar new)
}

int main() {
  auto r = fabrica("gpu");
  assert(r != nullptr);
  assert(r->nombre == "gpu");
  auto r2 = std::move(r);
  assert(r == nullptr);
  assert(r2->nombre == "gpu");
  return 0;
}
