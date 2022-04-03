#include <iostream>
#include <regex>
#include <string>

bool valid(const std::smatch& m) {
  if (m[1].matched)
    return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
  else
    return !m[3].matched && m[4].str() == m[6].str();
}

int main(int argc, char** argv) {
  std::string phone = "(\\()?(\\d{3})(\\))?([-.])?(\\d{3})([-.])?(\\d{4})";
  std::regex r(phone);

  std::smatch m;
  std::string s;
  std::string fmt = "$2.$5.$7";

  while (std::getline(std::cin, s)) {
    for (std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it;
         ++it) {
      if (valid(*it))
        std::cout << "Valid: "
                  << std::regex_replace(s, r, fmt,
                                        std::regex_constants::format_no_copy)
                  << std::endl;
      else
        std::cout << "Not valid: " << it->str() << std::endl;
    }
  }

  return 0;
}
