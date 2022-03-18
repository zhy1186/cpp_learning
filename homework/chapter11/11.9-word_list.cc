#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>

int main() {
  std::map<std::string, std::list<int>> words{};
  std::string word;
  int line;

  while (std::cin >> word >> line) {
    words[word].push_back(line);
  }

  for (auto i : words) {
    std::cout << "Word: " << i.first << " appears in line: " << std::endl;
    std::for_each(i.second.begin(), i.second.end(),
                  [](int& times) { std::cout << times << " " << std::endl; });
  }

  return 0;
}