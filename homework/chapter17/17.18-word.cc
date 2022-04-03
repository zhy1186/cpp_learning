#include <iostream>
#include <regex>
#include <unordered_set>

int main(int argc, char** argv) {
  std::string pattern = "[[:alpha:]]*[^c]ei[[:alpha:]]*";
  std::regex r(pattern);
  std::smatch results;

  std::unordered_set<std::string> ex{"leisure", "albeit", "neighbor"};
  std::string test_str =
      "abcde agree acdef receipt freind theif hahaha albeit today";
  for (std::sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
       it != end_it; ++it) {
    if (ex.find(it->str()) != ex.end()) continue;
    auto pos = it->prefix().length();
    pos = pos > 20 ? pos - 20 : 0;
    std::cout << it->prefix().str().substr(pos) << "\n\t\t>>> " << it->str()
              << " <<<\n"
              << it->suffix().str().substr(0, 20) << std::endl;
  }

  return 0;
}
