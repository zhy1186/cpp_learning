#include <iostream>
#include <list>
#include <string>

int main(int argc, char** argv) {
  std::list<std::string> test_list{};
  std::string input{};

  while (std::cin >> input) {
    test_list.push_back(input);
  }

  auto itr = test_list.cbegin();
  while (itr != test_list.cend()) {
    std::cout << *itr << std::endl;
    ++itr;
  }
  return 0;
}
