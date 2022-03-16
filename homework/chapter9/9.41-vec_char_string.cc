#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
  std::vector<char> cvec{'h', 'e', 'l', 'l', 'o'};
  std::string test(cvec.begin(), cvec.end());
  std::cout << test << std::endl;
  return 0;
}