#include <algorithm>
#include <iostream>
#include <list>
#include <string>

int main(int argc, char** argv) {
  std::list<std::string> vec{};

  std::string inp{};
  std::cout << "Input strings for list: for q to end\n";
  while (std::cin >> inp) {
    if (inp == "q") break;
    vec.push_back(inp);
  }

  std::cin.clear();
  std::cin.sync();

  std::string test{};
  std::cout << "Input string to count:" << std::endl;
  std::cin >> test;
  std::cout << test << " appears " << std::count(vec.begin(), vec.end(), test)
            << " times." << std::endl;
  return 0;
}
