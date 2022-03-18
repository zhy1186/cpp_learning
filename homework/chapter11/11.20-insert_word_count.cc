#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, std::size_t> word_count;
  std::string word;
  while (std::cin >> word) {
    auto ret = word_count.insert({word, 1});

    if (!ret.second) ++((ret.first)->second);
  }

  for (const auto &w : word_count) {
    std::cout << w.first << " occurs " << w.second << " time(s)" << std::endl;
  }

  return 0;
}