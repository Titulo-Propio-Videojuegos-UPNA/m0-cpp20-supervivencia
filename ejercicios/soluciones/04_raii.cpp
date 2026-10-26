#include <cassert>
#include <memory>
#include <string>

struct Recurso {
  explicit Recurso(std::string n) : nombre(std::move(n)) {}
  std::string nombre;
};

std::unique_ptr<Recurso> fabrica(const std::string& nombre) {
  return std::make_unique<Recurso>(nombre);
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
