#include <iostream>
#include <list>
#include <vector>

int main(int argc, char* argv[]) {
  std::list<int> test1{1, 2, 3, 5, 8};
  std::vector<int> test2{2, 4, 6, 8, 10};

  // question1
  std::vector<double> target1(test1.begin(), test1.end());
  for (auto i : target1) {
    std::cout << i << std::endl;
  }

  // question2
  std::vector<double> target2(test2.begin(), test2.end());
  for (auto j : target2) {
    std::cout << j << std::endl;
  }
  return 0;
}