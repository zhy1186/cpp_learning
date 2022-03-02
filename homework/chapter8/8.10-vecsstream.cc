#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<std::string> lines;
  std::string line;

  std::ifstream ifs(argv[1]);

  if (!ifs.good()) {
    std::cerr << "File Open Failed!" << std::endl;
    return -1;
  }

  while(getline(ifs, line)) {
    lines.push_back(line);
  }

  std::string test{};
  for (auto itr = lines.cbegin(); itr != lines.cend(); ++itr) {
    std::istringstream iss(*itr);

    while (iss >> test) {
      std::cout << test << std::endl;
    }
  }

  return 0;
}
