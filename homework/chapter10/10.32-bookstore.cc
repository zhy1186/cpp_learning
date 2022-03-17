#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "include/Sales_item.h"

int main() {
  Sales_item item;
  std::vector<Sales_item> record{};

  while (std::cin >> item) {
    record.push_back(item);
  }

  std::sort(record.begin(), record.end(), compareIsbn);

  auto beg = record.begin();
  while (beg != record.end()) {
    auto temp = beg;
    beg = std::find_if(beg, record.end(), [temp](const Sales_item& s) {
      return s.isbn() != (*temp).isbn();
    });
    std::cout << std::accumulate(temp, beg - 1, *temp) << std::endl;
  }

  return 0;
}
