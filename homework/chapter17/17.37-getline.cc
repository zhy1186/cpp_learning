#include <fstream>
#include <iostream>

int main() {
  char cs[10];
  std::ifstream ifs(
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter17/include/"
      "story.txt");
  while (ifs) {
    ifs.getline(cs, 9, '\n');
    std::cout << "line len: " << ifs.gcount() << std::endl;
    std::cout << cs << std::endl;
  }
  return 0;
}