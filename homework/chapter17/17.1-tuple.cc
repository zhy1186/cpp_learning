#include <iostream>
#include <tuple>

int main() {
  std::tuple<int, int, int> tpe{10, 20, 30};

  std::cout << std::get<0>(tpe) << std::endl;
  std::cout << std::get<1>(tpe) << std::endl;
  std::cout << std::get<2>(tpe) << std::endl;

  return 0;
}