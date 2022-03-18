#include <iostream>
#include <utility>
#include <vector>

int main() {
  std::vector<std::pair<std::string, int>> vec_pair{};

  std::string str{};
  int num{};
  while (std::cin >> str >> num) {
    // vec_pair.push_back(std::make_pair(str, num));
    vec_pair.push_back({str, num});
  }

  for (auto i : vec_pair) {
    std::cout << i.first << '\t' << i.second << std::endl;
  }

  return 0;
}
