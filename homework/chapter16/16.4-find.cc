#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename ITER, typename T>
ITER find(const ITER& beg, const ITER& end, T value) {
  ITER tmp = beg;
  while (tmp != end) {
    if (*tmp == value) return tmp;
    tmp++;
  }
  return end;
}

int main(int argc, char** argv) {
  std::vector<int> vec_int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << *find(vec_int.cbegin(), vec_int.cend(), 18) << std::endl;

  std::list<std::string> lst_str{"aaa", "bbb", "ccc", "ddd", "eee"};
  std::cout << *find(lst_str.cbegin(), lst_str.cend(), "ddd") << std::endl;

  return 0;
}
