#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool large(const std::string& s1) { return s1.size() > 5; }

int main() {
  std::vector<std::string> words = {"the",  "quick", "red",  "fox", "jumpsss",
                                    "over", "thsse", "slow", "red", "turtle"};

  auto itr = partition(words.begin(), words.end(), large);
  for (auto i = words.begin(); i != itr; ++i) {
    std::cout << *i << std::endl;
  }
}