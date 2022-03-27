#include <iostream>

static int a = 0;

struct numbers {
  numbers() { number = a++; }

  int number;
};

void f(numbers test) { std::cout << test.number << std::endl; }

int main(int argc, char** argv) {
  numbers a, b = a, c = b;
  f(a);
  f(b);
  f(c);
}
