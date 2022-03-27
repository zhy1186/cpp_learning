#include <iostream>

static int a = 0;

struct numbers {
  numbers() { number = a++; }
  numbers(const numbers& rhs) { number = a++; }
  numbers& operator=(const numbers& rhs) {
    number = a++;
    return *this;
  }

  int number;
};

void f(numbers test) { std::cout << test.number << std::endl; }

int main(int argc, char** argv) {
  numbers a, b = a, c = b;
  f(a);
  f(b);
  f(c);
}
