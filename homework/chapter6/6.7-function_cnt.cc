#include <iostream>

int cnt() {
  static int counter = 0;
  return ++counter;
}

int main() {
  int out = 0;
  for (int i = 0; i < 10; ++i) {
    out = cnt();
  }

  std::cout << out << std::endl;
  return 0; 
}
