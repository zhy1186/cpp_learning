#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> first_name1 = {"alice", "bob", "carol", "dave"};
  std::vector<std::string> first_name2 = {"eve", "francis", "grace", "henry"};

  std::string last_name1 = "last1";
  std::string last_name2 = "last2";

  std::map<std::string, std::vector<std::string>> names{};
  names.insert(std::pair<std::string, std::vector<std::string>>(last_name1,
                                                                first_name1));
  names.insert(std::pair<std::string, std::vector<std::string>>(last_name2,
                                                                first_name2));

  names["last1"].push_back("haha");

  for (auto i : names["last1"]) {
    std::cout << i << std::endl;
  }

  return 0;
}
