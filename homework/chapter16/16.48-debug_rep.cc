#include <iostream>
#include <sstream>
#include <string>

template <typename T>
std::string debug_rep(const T &t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T>
std::string debug_rep(T *p) {
  std::ostringstream ret;
  ret << "pointer: " << p;
  if (p)
    ret << " " << debug_rep(*p);
  else
    ret << " null pointer.";
  return ret.str();
}

std::string debug_rep(const std::string &s) { return '"' + s + '"'; }

std::string debug_rep(char *p) { return debug_rep(std::string(p)); }

std::string debug_rep(const char *p) { return debug_rep(std::string(p)); }

int main(int argc, char **argv) {
  std::string s = "hi";
  const std::string *sp = &s;
  std::cout << debug_rep(sp) << std::endl;
  return 0;
}