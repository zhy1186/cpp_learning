#include <vector>

#include "include/String.h"

int main() {
  std::vector<String> vec{};
  vec.push_back(String("aaa"));
  vec.push_back(String("bbb"));
  vec.push_back(String("ccc"));

  return 0;
}
