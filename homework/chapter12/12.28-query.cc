#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
  std::string path =
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter12/include/test.txt";
  std::ifstream ifs(path);

  std::vector<std::string> content{};
  std::map<std::string, std::set<int>> word_info{};

  std::string line{};
  int line_number = 0;

  while (std::getline(ifs, line)) {
    content.push_back(line);
    ++line_number;
    std::istringstream iss(line);
    std::string word{};
    while (iss >> word) {
      auto& word_line_nums = word_info[word];
      word_line_nums.insert(line_number);
    }
  }

  while (true) {
    std::cout << "Input a word to look up, q to quit:" << std::endl;
    std::string target;
    if (!(std::cin >> target) || target == "q") break;
    auto location = word_info.find(target);
    if (location == word_info.end()) {
      std::cout << "Not found in article!" << std::endl;
      continue;
    } else
      std::cout << target << " occurs " << location->second.size() << " times. "
                << std::endl;
    for (auto i : location->second) {
      std::cout << *(content.begin() + i) << std::endl;
    }
  }
  return 0;
}