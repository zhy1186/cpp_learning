#include <algorithm>
#include <iostream>
#include <list>

int main() {
  std::list<int> lst = {0, 2, 4, 5, 0, 4, 7, 6, 0, 8};
  auto itr = std::find(lst.crbegin(), lst.crend(), 0);

  for (; itr != lst.crend(); --itr) {
    std::cout << *itr << std::endl;
  }

  return 0;
}
