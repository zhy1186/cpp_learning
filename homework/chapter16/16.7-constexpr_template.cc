#include <iostream>

template <typename T, unsigned U>
constexpr unsigned get_size(T (&arr)[U]) {
  return U;
}

int main(int argc, char** argv) {
  int test[5] = {1, 2, 3, 4};

  std::cout << get_size(test) << std::endl;

  return 0;
}
