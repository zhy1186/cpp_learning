#include <algorithm>
#include <vector>

#include "include/Sales_data.h"

int main() {
  std::vector<Sales_data> vec = {Sales_data("1", 2, 3), Sales_data("2", 2, 6),
                                 Sales_data("3", 6, 9), Sales_data("3", 5, 8),
                                 Sales_data("1", 6, 2), Sales_data("1", 8, 8),
                                 Sales_data("1", 2, 3), Sales_data("2", 4, 4)};

  std::stable_sort(vec.begin(), vec.end(),
                   [](const Sales_data& s1, const Sales_data& s2) {
                     return s1.isbn() < s2.isbn();
                   });

  for (auto& i : vec) {
    print(std::cout, i);
  }
}
