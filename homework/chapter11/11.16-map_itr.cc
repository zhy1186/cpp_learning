#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> test_map = {std::make_pair("abc", 1)};
  std::map<std::string, int>::iterator itr = test_map.begin();
  itr->second = 6;

  std::cout << test_map["abc"] << std::endl;
  return 0;
}
