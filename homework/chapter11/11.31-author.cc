#include <iostream>
#include <map>
#include <string>

int main() {
  std::multimap<std::string, std::string> auth_book{};
  std::string author{}, book{};
  while (std::cin >> author >> book) {
    auth_book.insert({author, book});
  }

  auto iter = auth_book.find("david");
  auto n = auth_book.count("david");

  while (--n) {
    auth_book.erase(iter++);
  }

  for (auto i : auth_book) {
    std::cout << i.first << '\t' << i.second << std::endl;
  }

  return 0;
}
