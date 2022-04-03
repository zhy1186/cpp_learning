#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

int main() {
  std::string a = "aaa";
  std::vector<std::string> b = {"b", "bb", "bbb", "bbbb"};
  std::pair<std::string, int> c{"eee", 5};

  auto tpe = std::make_tuple(a, b, c);
  return 0;
}