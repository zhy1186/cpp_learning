#include <iostream>
#include <regex>

int main(int argc, char** argv) {
  std::string pattern = "[[:alpha:]]*[^c]ei[[:alpha:]]*";
  std::regex r(pattern);
  std::smatch results;

  std::string test_str = "receipt freind neighbor theif today leisure albeit";
  for (std::sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
       it != end_it; ++it) {
    std::cout << it->str() << std::endl;
  }

  return 0;
}
