#include <cassert>
#include <memory>
#include <string>

struct Actor {
  virtual ~Actor() = default;
  virtual std::string etiqueta() const = 0;
};

struct Pawn : Actor {
  std::string etiqueta() const override { return "pawn"; }
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
