#include <iostream>
#include <string>

std::string change(std::string name, std::string prefix, std::string suffix) {
  name.insert(name.begin(), prefix.begin(), prefix.end());
  name.insert(name.end(), suffix.begin(), suffix.end());

  return name;
}

int main() {
  std::string name = "Alice";
  std::string prefix = "Mrs. ";
  std::string suffix = " III";
  std::cout << change(name, prefix, suffix);

  return 0;
}
