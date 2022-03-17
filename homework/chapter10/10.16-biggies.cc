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
  auto wc = std::find_if(words.begin(), words.end(),
                         [sz](std::string& a) { return a.size() >= sz; });

  auto count = words.end() - wc;
  std::cout << count << " words larger or equal than " << sz << std::endl;

  std::for_each(wc, words.end(),
                [](std::string& s) { std::cout << s << std::endl; });
}

int main() {
  std::vector<std::string> words = {"the",  "quick", "red",  "fox", "jumps",
                                    "over", "the",   "slow", "red", "turtle"};
  biggies(words, 3);

  return 0;
}
