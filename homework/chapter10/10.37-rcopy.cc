#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::sort(vec.begin(), vec.end());
  auto itr = std::partition(vec.begin(), vec.end(),
                            [](int i) { return (i > 3 && i < 7); });
  std::vector<int> vec2(5);
  std::copy(vec.begin(), itr, vec2.rbegin());

  for (auto i : vec2) {
    std::cout << i << std::endl;
  }
  return 0;
}