#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

int main(int argc, char* argv[]) {
  std::string line, word;
  std::vector<PersonInfo> people;

  std::istringstream record;
  std::fstream ifs(argv[1]);

  while(getline(ifs, line)) {
    PersonInfo info;

    record.clear();
    record.str(line);

    record >> info.name;
    while(record >> word) {
      info.phones.push_back(word);
    }

    people.push_back(info);
  }

  return 0;
}
