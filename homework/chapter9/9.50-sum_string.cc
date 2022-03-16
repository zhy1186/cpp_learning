#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vec{"12", "34", "56", "78"};
  int sum = 0;
  for (auto i : vec) {
    sum += std::stoi(i);
  }

  std::cout << sum << std::endl;
  return 0;
}
