#include <iostream>

void swap(int& rp, int& rb) {
  int temp;
  temp = rp;
  rp = rb;
  rb = temp;
}

int main() {
  int a = 9, b = 12;

  swap(a, b);
  std::cout << a << "   " << b << std::endl;
}
