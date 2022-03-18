#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, std::size_t> word_count;
  std::string word;
  while (std::cin >> word) {
    for (auto itr = word.begin(); itr != word.end(); ++itr) {
      *itr = std::tolower(*itr);
    }
    word.erase(std::remove_if(word.begin(), word.end(),
                              [](const char c) { return std::ispunct(c); }),
               word.end());

    ++word_count[word];
  }

  for (const auto &w : word_count) {
    std::cout << w.first << " occurs " << w.second << " time(s)" << std::endl;
  }

  return 0;
}
