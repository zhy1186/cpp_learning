#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string>& words) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string>& words,
             std::vector<std::string>::size_type sz) {
  elimDups(words);
  std::stable_sort(words.begin(), words.end(),
                   [](const std::string& a, const std::string& b) {
                     return a.size() < b.size();
                   });
  auto wc =
      std::stable_partition(words.begin(), words.end(),
                            [sz](std::string& a) { return a.size() >= sz; });

  auto ctr =
      std::count_if(words.begin(), words.end(), [sz](std::string& s) -> bool {
        if (s.size() > 6)
          return true;
        else
          return false;
      });
  std::cout << ctr << " words longer than 6." << std::endl;
}

int main() {
  std::vector<std::string> words = {"the",     "qudddick", "red",      "fox",
                                    "jumps",   "over",     "tdddddhe", "slow",
                                    "reddddd", "turtle"};
  biggies(words, 3);

  return 0;
}
