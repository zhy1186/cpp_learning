#include <iostream>
#include <initializer_list>

int sumup (std::initializer_list<int> lst) {
  int sum{};
  for (auto& i : lst) {
    sum += i;
  }
  return sum;
}

int main(int argc, char** argv) {
  std::cout << sumup({1, 2, 3, 4, 5}) << std::endl;
  return 0;
}
