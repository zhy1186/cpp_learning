#include <deque>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::deque<std::string> test_deque{};
  std::string input{};
  while (std::cin >> input) {
    test_deque.push_back(input);
  }

  for (auto i : test_deque) {
    std::cout << i << std::endl;
  }

  return 0;
}
