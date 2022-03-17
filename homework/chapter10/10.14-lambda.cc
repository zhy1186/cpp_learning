#include <iostream>

int main() {
  auto f = [](const int& a, const int& b) { return (a + b); };
  std::cout << f(4, 6) << std::endl;
  return 0;
}