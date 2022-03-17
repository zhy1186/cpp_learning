#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool check_size(std::string s, int sz) { return s.size() < sz; }

int main() {
  std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::string test_str = "abcde";

  // auto itr = std::find_if(test.begin(), test.end(),
  //                         [test_str](int i) { return i > test_str.size(); });
  auto itr =
      std::find_if(test.begin(), test.end(),
                   std::bind(check_size, test_str, std::placeholders::_1));
  std::cout << *itr << std::endl;

  return 0;
}
