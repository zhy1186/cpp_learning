#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string>& words) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

bool isShorter(const std::string& str1, const std::string& str2) {
  return str1.size() < str2.size();
}

int main() {
  std::vector<std::string> words = {"the",  "quick", "red",  "fox", "jumps",
                                    "over", "the",   "slow", "red", "turtle"};
  elimDups(words);
  std::stable_sort(words.begin(), words.end(), isShorter);

  for (auto& i : words) {
    std::cout << i << std::endl;
  }

  return 0;
}
