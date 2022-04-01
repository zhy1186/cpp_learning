#include <iostream>

template <typename T, unsigned U>
const T* begin(const T (&arr)[U]) {
  return arr;
}

template <typename T, unsigned U>
const T* end(const T (&arr)[U]) {
  return arr + U;
}

int main(int argc, char** argv) {
  double test[4] = {1.23, 2.34, 3.45, 4.56};

  std::cout << *begin(test) << std::endl;
  std::cout << *end(test) << std::endl;

  return 0;
}
