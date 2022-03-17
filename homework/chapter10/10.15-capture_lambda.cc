#include <iostream>

int main() {
  int a = 6;
  auto f = [a](const int& b) { return (a + b); };
  std::cout << f(8) << std::endl;
  return 0;
}
