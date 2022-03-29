#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Larger {
 public:
  Larger() {}
  Larger(int sz) : sz_(sz) {}
  bool operator()(const std::string& a, const std::string& b) {
    return a.size() < b.size();
  }

  bool operator()(std::string& s) { return s.size() >= sz_; }

 private:
  int sz_;
};

void elimDups(std::vector<std::string>& words) {
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string>& words,
             std::vector<std::string>::size_type sz) {
  elimDups(words);
  std::stable_sort(words.begin(), words.end(), Larger());
  auto wc = std::partition(words.begin(), words.end(), Larger(sz));

  auto count = wc - words.begin();
  std::cout << count << " words larger or equal than " << sz << std::endl;

  std::for_each(words.begin(), wc,
                [](std::string& s) { std::cout << s << std::endl; });
}

int main() {
  std::vector<std::string> words = {"the",  "quick", "red",  "fox", "jumps",
                                    "over", "the",   "slow", "red", "turtle"};
  biggies(words, 3);

  return 0;
}
