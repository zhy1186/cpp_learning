#include <iostream>
#include <string>

int main() {
  std::string test = "ab2c3d7R4E6";
  std::string numer = "23467";
  std::string letter = "abcdRE";

  std::string::size_type pos = 0;

  while ((pos = test.find_first_of(numer, pos)) != std::string::npos) {
    std::cout << "number at index " << pos << " numer is: " << test[pos]
              << std::endl;
    ++pos;
  }

  pos = 0;
  while ((pos = test.find_first_not_of(numer, pos)) != std::string::npos) {
    std::cout << "letter at index " << pos << " letter is: " << test[pos]
              << std::endl;
    ++pos;
  }
}
