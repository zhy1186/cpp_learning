#include <iostream>
#include <list>

int main(int argc, char** argv) {
  std::list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto iter = lst.begin();
  while (iter != lst.end()) {
    if (*iter % 2) {
      iter = lst.insert(iter, *iter);
      ++iter;
      ++iter;
    } else
      iter = lst.erase(iter);
  }

  for (auto i : lst) std::cout << i << std::endl;
  return 0;
}
