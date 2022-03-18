#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> first_name1 = {"alice", "bob", "carol", "dave"};
  std::vector<std::string> first_name2 = {"eve", "francis", "grace", "henry"};

  std::string last_name1 = "last1";
  std::string last_name2 = "last2";

  std::vector<std::string> birthday1 = {"0101", "0102", "0103", "0104"};
  std::vector<std::string> birthday2 = {"0201", "0202", "0203", "0204"};

  std::map<std::string,
           std::pair<std::vector<std::string>, std::vector<std::string>>>
      names_birthday{};
  names_birthday.insert(
      std::make_pair(last_name1, std::make_pair(first_name1, birthday1)));
  names_birthday.insert(
      std::make_pair(last_name2, std::make_pair(first_name2, birthday2)));

  names_birthday["last1"].first.push_back("haha");

  for (auto i : names_birthday["last1"].first) {
    std::cout << i << std::endl;
  }

  return 0;
}