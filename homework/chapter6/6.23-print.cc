#include <iostream>
#include <iterator>

void print(int a) {
  std::cout << a << std::endl;
}

void print(int* a, int* b) {
  for (; a != b; ++a){
    std::cout << *a << std::endl;
  }
}

int main() {
  int i = 0, j[2] = {0, 1};

  print(i);
  print(std::begin(j), std::end(j));
  return 0;
} 
