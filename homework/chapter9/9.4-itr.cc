#include <iostream>
#include <vector>

bool find(std::vector<int>::iterator itr1, std::vector<int>::iterator itr2, int value) {
  bool find = false;
  while (itr1 != itr2) {
    if (*itr1 == value) find = true;
    ++itr1;
  }
  return find;
}

int main(int argc, char** argv) {
  std::vector<int> test{1, 4, 6, 8, 10, 14, 2};
  std::cout << find(test.begin(), test.end(), 8);

  return 0;
}
