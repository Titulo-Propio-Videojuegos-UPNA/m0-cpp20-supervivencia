#include <cassert>
#include <string>

template <typename T>
T mayor(T a, T b) {
  return (a < b) ? b : a;
}

int main() {
  assert(mayor(2, 9) == 9);
  assert(mayor(3.0, 1.5) == 3.0);
  assert(mayor(std::string{"aa"}, std::string{"b"}) == "b");
  return 0;
}
