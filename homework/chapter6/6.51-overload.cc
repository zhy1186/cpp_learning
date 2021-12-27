#include <iostream>

void f() {
  std::cout << "void f()" << __LINE__ << std::endl; 
}

void f(int) {
  std::cout << "void f(int)" << __LINE__ << std::endl;
}

void f(int, int) {
  std::cout << "void f(int int)" << __LINE__ << std::endl;
}

void f(double, double = 3.14) {
  std::cout << "void f(double, double = 3.14)" << __LINE__ << std::endl;
}

int main() {
//  f(2.56, 42);
  f(42);
  f(42, 0);
  f(2.56, 3.14);
  return 0;
}
