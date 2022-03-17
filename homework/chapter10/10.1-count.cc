#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  std::vector<int> vec{};

  int inp{};
  std::cout << "Input numbers for vector: for q to end\n";
  while (std::cin >> inp) {
    if (inp == 'q') break;
    vec.push_back(inp);
  }

  std::cin.clear();
  std::cin.sync();

  int test{};
  std::cout << "Input number to count:" << std::endl;
  std::cin >> test;
  std::cout << test << " appears " << std::count(vec.begin(), vec.end(), test)
            << " times." << std::endl;
  return 0;
}
