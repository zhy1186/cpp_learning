#include <iostream>

void reset(int& ref) {
  ref = 0;
}

int main() {
  int test = 8;
  reset(test);
  std::cout << test << std::endl;

  return 0;
}
