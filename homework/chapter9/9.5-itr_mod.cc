#include <iostream>
#include <vector>

std::vector<int>::iterator find(std::vector<int>::iterator itr1,
                                std::vector<int>::iterator itr2, int value) {
  while (itr1 != itr2) {
    if (*itr1 == value) return itr1;
    ++itr1;
  }
  return itr2;
}

int main(int argc, char** argv) {
  std::vector<int> test{1, 4, 6, 8, 10, 14, 2};
  std::vector<int>::iterator result = find(test.begin(), test.end(), 80);
  if (result == test.end()) {
    std::cout << "Could not find!";
    return -1;
  }
  std::cout << "Find " << *result;

  return 0;
}
