#include <algorithm>
#include <vector>

#include "include/Sales_data.h"

bool compareisbn(const Sales_data& s1, const Sales_data& s2) {
  const auto& isbn1 = s1.isbn();
  const auto& isbn2 = s2.isbn();
  return isbn1 < isbn2;
}

int main() {
  std::vector<Sales_data> vec = {Sales_data("1", 2, 3), Sales_data("2", 2, 6),
                                 Sales_data("3", 6, 9), Sales_data("3", 5, 8),
                                 Sales_data("1", 6, 2), Sales_data("1", 8, 8),
                                 Sales_data("1", 2, 3), Sales_data("2", 4, 4)};

  std::stable_sort(vec.begin(), vec.end(), compareisbn);

  for (auto& i : vec) {
    print(std::cout, i);
  }
}
