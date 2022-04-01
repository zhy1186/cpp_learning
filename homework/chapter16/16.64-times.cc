#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
int show_times(const std::vector<T> &vec, const T val) {
  return std::count_if(vec.begin(), vec.end(),
                       [val](const T val2) { return val == val2; });
}

template <>
int show_times(const std::vector<const char *> &vec, const char *val) {
  return std::count_if(vec.begin(), vec.end(), [val](const char *val2) {
    return std::strcmp(val, val2);
  });
}

int main(int argc, char **argv) {
  std::vector<int> vec{1, 2, 3, 8, 5, 8, 7, 8, 9, 10};
  std::cout << show_times(vec, 8) << std::endl;

  std::vector<double> vec2{1.11, 2.22, 3.33, 2.22, 3.33,
                           4.44, 1.23, 1.11, 2.22};
  std::cout << show_times(vec2, 2.22) << std::endl;

  std::vector<std::string> vecs{"aaa", "bbb", "aaa", "ccc",
                                "Edc", "aaa", "WEA"};
  std::cout << show_times(vecs, std::string("aaa")) << std::endl;

  std::vector<char *> vecc{(char *)"aaa", (char *)"bbb", (char *)"aaa",
                           (char *)"ccc", (char *)"Edc", (char *)"aaa",
                           (char *)"WEA"};
  char *cstr = (char *)"aaa";
  std::cout << show_times<char *>(vecc, cstr) << std::endl;

  return 0;
}