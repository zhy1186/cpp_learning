#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::ostream_iterator<int> os(std::cout, "\n");

  for (auto i = vec.crbegin(); i != vec.crend(); ++i) {
    *os++ = *i;
  }

  return 0;
}