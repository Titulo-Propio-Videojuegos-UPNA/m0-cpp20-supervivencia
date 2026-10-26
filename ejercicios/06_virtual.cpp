// M0.06 — virtual / override. LearnCpp ch. 24–25. Core Guidelines C.128
#include <cassert>
#include <memory>
#include <string>

struct Actor {
  virtual ~Actor() = default;
  virtual std::string etiqueta() const = 0;
};

struct Pawn : Actor {
  std::string etiqueta() const override {
    return "";  // TODO: devuelve el identificador en minúsculas correspondiente a esta clase derivada
  }
};

std::string via_base(const Actor& a) { return a.etiqueta(); }

int main() {
  Pawn p;
  const Actor& ref = p;
  assert(ref.etiqueta() == "pawn");
  assert(via_base(p) == "pawn");
  std::unique_ptr<Actor> heap = std::make_unique<Pawn>();
  assert(heap->etiqueta() == "pawn");
  return 0;
}
