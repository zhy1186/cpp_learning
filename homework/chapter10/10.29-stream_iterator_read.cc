#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  std::ifstream ifs(
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter10/include/text.txt");

  std::istream_iterator<std::string> stream_iter(ifs), eof;
  std::vector<std::string> words{};

  while (stream_iter != eof) {
    words.push_back(*stream_iter++);
  }

  for (auto& i : words) {
    std::cout << i << std::endl;
  }
  return 0;
}
