#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::deque<int> lst1, lst2, lst3;

  std::copy(vec.begin(), vec.end(), std::inserter(lst1, lst1.begin()));
  std::copy(vec.begin(), vec.end(), std::back_inserter(lst2));
  std::copy(vec.begin(), vec.end(), std::front_inserter(lst3));

  for (int i = 0; i < 9; ++i) {
    std::cout << lst1.at(i) << '\t' << lst2.at(i) << '\t' << lst3.at(i) << '\t'
              << std::endl;
  }
}