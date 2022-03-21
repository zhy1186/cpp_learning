#include <cstring>
#include <iostream>

int main() {
  const char *s1 = "Hello", *s2 = "World";
  char* p = new char[std::strlen(s1) + std::strlen(s2)];

  for (int i = 0; i < std::strlen(s1); ++i) {
    p[i] = s1[i];
  }
  for (int j = 0; j < std::strlen(s2); ++j) {
    p[std::strlen(s1) + j] = s2[j];
  }

  for (int k = 0; k < std::strlen(s1) + std::strlen(s2); ++k) {
    std::cout << p[k];
  }

  delete[] p;
  return 0;
}