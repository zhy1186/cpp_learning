#include <forward_list>
#include <iostream>
#include <string>

std::forward_list<std::string> test_function(
    std::forward_list<std::string> flst, std::string find_string,
    std::string insert_string) {
  auto prev = flst.before_begin();
  for (auto itr = flst.begin(); itr != flst.end(); ++itr) {
    if (*itr == find_string) {
      itr = flst.insert_after(itr, insert_string);
      return flst;
    } else {
      prev = itr;
    }
  }
  flst.insert_after(prev, insert_string);
  return flst;
}

int main(int argc, char** argv) {
  std::forward_list<std::string> flst = {"abc", "def", "ghi", "jkl", "mno"};
  auto rtn_list = test_function(flst, "awiebi", "hahaha");

  for (auto i : rtn_list) std::cout << i << std::endl;
  return 0;
}