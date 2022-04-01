#include <iostream>

template <typename T, unsigned U>
void print(T (&arr)[U]) {
  for (auto elem : arr) {
    std::cout << elem << std::endl;
  }
  return;
}

int main(int argc, char** argv) {
  double test[4] = {1.23, 2.34, 3.45, 4.56};
  print(test);
  return 0;
}
