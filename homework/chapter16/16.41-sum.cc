#include <iostream>

template <typename T>
auto sum(const T& v1, const T& v2) -> decltype(v1 + v2) {
  return v1 + v2;
}

int main(int argc, char** argv) {
  std::cout << sum<long>(999999999999, 999999999) << std::endl;
}
