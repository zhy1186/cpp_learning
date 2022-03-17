#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::vector<int> vec = {1, 1, 2, 3, 4, 5, 5, 2, 1, 3, 1, 2, 6, 5,
                          4, 7, 8, 5, 7, 8, 9, 4, 7, 3, 2, 8, 9, 0};
  std::list<int> lst{};

  std::unique_copy(vec.cbegin(), vec.cend(), std::inserter(lst, lst.begin()));

  for (auto i : lst) {
    std::cout << i << std::endl;
  }
}
