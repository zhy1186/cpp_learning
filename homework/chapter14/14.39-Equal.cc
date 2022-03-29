#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Equal {
 public:
  Equal(int length) : length_(length) {}
  bool operator()(std::string& s) { return length_ == s.size(); }

 private:
  int length_;
};

int main(int argc, char** argv) {
  std::string path =
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter14/include/test.txt";
  std::ifstream ifs(path);

  std::vector<std::string> content;
  std::string word;

  while (ifs >> word) {
    content.push_back(word);
  }

  int counter = 0;
  for (int i = 1; i <= 9; ++i) {
    Equal test(i);
    for (auto j : content) {
      if (test(j)) counter++;
    }
  }
  std::cout << "There are " << counter << " words length between 1 and 9."
            << std::endl;

  std::cout << "There are " << content.size() - counter << " longer than 10"
            << std::endl;

  return 0;
}
