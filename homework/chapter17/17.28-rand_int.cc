#include <iostream>
#include <random>

unsigned func(const int& seed, const int& min, const int& max) {
  static std::default_random_engine e(seed);
  static std::uniform_int_distribution<unsigned> u(min, max);
  return u(e);
}

int main(int argc, char** argv) {
  for (int i = 0; i < 10; ++i) {
    std::cout << func(998, 0, 9) << std::endl;
  }

  return 0;
}
