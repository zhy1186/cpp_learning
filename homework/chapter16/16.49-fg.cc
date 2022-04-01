#include <iostream>

template <typename T>
void f(T) {
  std::cout << "template <typename T> void f(T)" << std::endl;
}

template <typename T>
void f(const T*) {
  std::cout << "template <typename T> void f(const T*) " << std::endl;
}

template <typename T>
void g(T) {
  std::cout << "template <typename T> void g(T)" << std::endl;
}

template <typename T>
void g(T*) {
  std::cout << "template <typename T> void g(T*) " << std::endl;
}

int main(int argc, char** argv) {
  int i = 42, *p = &i;
  const int ci = 0, *p2 = &ci;
  g(42);
  g(p);
  g(ci);
  g(p2);
  f(42);
  f(p);
  f(ci);
  f(p2);
  return 0;
}
