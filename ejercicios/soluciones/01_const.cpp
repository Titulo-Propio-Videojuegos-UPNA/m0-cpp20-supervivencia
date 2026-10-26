#include <cassert>
#include <string>

int longitud(const std::string& s) { return static_cast<int>(s.size()); }

int main() {
  const std::string h = "hola";
  assert(longitud(h) == 4);
  assert(longitud(std::string{}) == 0);
  return 0;
}
