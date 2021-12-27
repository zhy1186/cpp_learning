#include <iostream>

void swap(int* pa, int* pb) {
  int temp;
  temp = *pa;
  *pa = *pb;
  *pb = temp;
}

int main() {
  int a = 9, b = 12;

  swap(&a, &b);
  std::cout << a << "   " << b << std::endl;
}
