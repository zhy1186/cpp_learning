#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::string noneed("bdfhkltgjpqy");
  std::string word, result;

  std::string file_name = argv[1];
  std::ifstream in(file_name);
  while (in >> word) {
    if (word.find_first_of(noneed) == std::string::npos &&
        word.size() > result.size())
      result = word;
  }
  std::cout << result << std::endl;
}
