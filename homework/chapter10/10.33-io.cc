#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  std::string input_file_path =
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter10/include/"
      "numbers.txt";
  std::string odd_file_path = "odd.txt";
  std::string even_file_path = "even.txt";

  std::ifstream ifs(input_file_path);
  std::istream_iterator<int> ifs_itr(ifs), eof;

  std::vector<int> numbers{};
  while (ifs_itr != eof) {
    numbers.push_back(*ifs_itr++);
  }

  auto part = std::partition(numbers.begin(), numbers.end(),
                             [](int i) { return i % 2 == 0; });

  std::ofstream ofs_odd(odd_file_path);
  std::ofstream ofs_even(even_file_path);
  std::ostream_iterator<int> ofs_itr_odd(ofs_odd, "\n"),
      ofs_itr_even(ofs_even, "\t");

  for (auto i = numbers.begin(); i != part; ++i) {
    *ofs_itr_odd++ = *i;
  }
  for (auto i = part; i != numbers.end(); ++i) {
    *ofs_itr_even++ = *i;
  }

  return 0;
}
