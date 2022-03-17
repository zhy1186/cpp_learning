#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> vec{};
  std::fill_n(std::back_inserter(vec), 10, 0);

  for (auto& i : vec) {
    std::cout << i << std::endl;
  }
  return 0;
}
