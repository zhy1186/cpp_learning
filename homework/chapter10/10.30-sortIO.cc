#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::string path =
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter10/include/"
      "numbers.txt";
  std::ifstream ifs(path);
  std::istream_iterator<int> iter_ifs(ifs), eof;

  std::vector<int> numbers{};
  while (iter_ifs != eof) {
    numbers.push_back(*iter_ifs++);
  }

  std::sort(numbers.begin(), numbers.end());
  std::vector<int> output{};
  auto ister = std::inserter(output, output.begin());
  std::copy(numbers.begin(), numbers.end(), ister);

  for (auto i : output) {
    std::cout << i << std::endl;
  }

  return 0;
}
