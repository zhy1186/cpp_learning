#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {
  std::vector<std::string> words{};
  std::string word{};
  std::fstream ifs("content.txt");

  if (!ifs.good()) {
  	std::cerr << "Open file failed" << std::endl;
  	return -1;
  }

  while(ifs >> word) {
  	words.push_back(word);
  }

  ifs.close();

  auto itr = words.cbegin();
  while(itr != words.cend()) {
  	std::cout << *itr << std::endl;
  	++itr;
  }

  return 0;
}
