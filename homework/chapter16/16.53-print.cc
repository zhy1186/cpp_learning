#include <iostream>

template <typename T>
std::ostream& print(std::ostream& os, const T& t) {
  return os << t;
}

template <typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args... rest) {
  os << t << ", ";
  return print(os, rest...);
}

int main(int argc, char** argv) {
  std::string s("sssss");
  int a = 1, b = 2, c = 3;
  double d = 3.1415;
  print(std::cout, a, b, c, s, d);
  return 0;
}
