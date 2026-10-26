// M0.05 — clase. LearnCpp ch. 14–15.
#include <cassert>
#include <stdexcept>

class Cuenta {
  int saldo_ = 0;

 public:
  explicit Cuenta(int saldo_inicial) : saldo_(saldo_inicial) {
    (void)saldo_inicial;
    // TODO: verifica la invariante y lanza excepción estándar si el saldo inicial es negativo
  }

  int saldo() const { return saldo_; }

  void ingresar(int n) {
    (void)n;
    // TODO: actualiza el saldo sumando el importe ingresado
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
