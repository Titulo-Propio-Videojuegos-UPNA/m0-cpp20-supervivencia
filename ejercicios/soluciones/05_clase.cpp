#include <cassert>
#include <stdexcept>

class Cuenta {
  int saldo_ = 0;

 public:
  explicit Cuenta(int saldo_inicial) : saldo_(saldo_inicial) {
    if (saldo_inicial < 0) throw std::invalid_argument("saldo");
  }

  int saldo() const { return saldo_; }

  void ingresar(int n) {
    if (n < 0) throw std::invalid_argument("ingreso");
    saldo_ += n;
  }
};

int main() {
  Cuenta c(10);
  c.ingresar(5);
  assert(c.saldo() == 15);
  bool ok = false;
  try {
    Cuenta mala(-1);
  } catch (const std::invalid_argument&) {
    ok = true;
  }
  assert(ok);
  return 0;
}
