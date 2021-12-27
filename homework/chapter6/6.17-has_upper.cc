#include <iostream>
#include <string>
#include <cctype>

bool has_upper(const std::string& svar) {
  bool hasupper = 1;
  for (auto& i : svar) {
    hasupper *= islower(i);
  }
 
  return !hasupper;
}

std::string to_lower(std::string& svar) {
  if (has_upper(svar)){
    std::cout << "Upper case dected! " << std::endl;
    for (auto &i : svar) {
      i = tolower(i);
    }
  }
  return svar;
}

int main() {
  std::cout << "Input string: " << std::endl;
  std::string test{};
  std::cin >> test;
  std::cout << to_lower(test) << std::endl;

  return 0;
}
