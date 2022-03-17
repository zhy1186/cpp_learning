#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string>& words) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

bool check_size(std::string& s, int sz) { return s.size() > sz; }

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

  auto ctr = std::count_if(words.begin(), words.end(),
                           std::bind(check_size, std::placeholders::_1, sz));
  std::cout << ctr << " words longer than 3." << std::endl;
}

int main() {
  std::vector<std::string> words = {"the",  "quick", "red",  "fox", "jumps",
                                    "over", "the",   "slow", "red", "turtle"};
  biggies(words, 3);

  return 0;
}
