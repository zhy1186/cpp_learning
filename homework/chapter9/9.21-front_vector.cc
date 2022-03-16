#include <iostream>
#include <list>
#include <vector>

int main(int argc, char** argv) {
  std::vector<std::string> vec{};
  auto itr = vec.begin();
  std::string word{};

  while (std::cin >> word) {
    itr = vec.insert(itr, word);
  }
}
