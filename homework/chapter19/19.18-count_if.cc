#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::size_t how_many(std::vector<std::string>& svec) {
  return std::count_if(svec.cbegin(), svec.cend(),
                       std::bind(&std::string::empty, std::placeholders::_1));
  /* return std::count_if(svec.cbegin(), svec.cend(),
                       std::mem_fn(&std::string::empty)); */
}

int main(int argc, char** argv) {
  std::vector<std::string> test{"aaa", "", "ccc", "nnn", "", "ddd"};
  std::cout << how_many(test) << std::endl;

  return 0;
}
