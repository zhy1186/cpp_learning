#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

const std::string &transform(const std::string &s,
                             const std::map<std::string, std::string> &m) {
  return m.at(s);
}

std::map<std::string, std::string> buildMap(std::ifstream &map_file) {
  std::map<std::string, std::string> trans_map{};
  std::string key{}, value{};
  while (map_file >> key && getline(map_file, value)) {
    if (value.size() > 1)
      trans_map[key] = value.substr(1);
    else
      throw std::runtime_error("no rule for: " + key);
  }
  return trans_map;
}

void word_transform(std::ifstream &map_file, std::ifstream &input) {
  auto trans_map = buildMap(map_file);
  std::string text{};
  while (std::getline(input, text)) {
    std::istringstream stream(text);
    std::string word{};
    bool first_word = true;
    while (stream >> word) {
      if (first_word)
        first_word = false;
      else
        std::cout << " ";
      std::cout << transform(word, trans_map);
    }
    std::cout << std::endl;
  }
}

int main(int argc, char **argv) {
  std::string map_file = "map.txt";
  std::string input_file = "input.txt";

  std::ifstream ifs_map(map_file);
  std::ifstream ifs_inp(input_file);

  word_transform(ifs_map, ifs_inp);
  return 0;
}
