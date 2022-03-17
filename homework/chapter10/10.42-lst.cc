#include <algorithm>
#include <iostream>
#include <list>

int main() {
  std::list<std::string> words = {"the",  "quick", "red",  "fox", "jumps",
                                  "over", "the",   "slow", "red", "turtle"};
  words.sort();
  words.unique();

  for (auto& i : words) {
    std::cout << i << std::endl;
  }

  return 0;
}
