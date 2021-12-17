#include <iostream>
int main(){
  int a{};
  double b{};
  unsigned c{};
  short d{};
  long f{};
  long long g{};
  char e{};

  std::cout << "int " << sizeof(a) << std::endl;
  std::cout << "double " << sizeof(b) << std::endl;
  std::cout << "unsigned " << sizeof(c) << std::endl;
  std::cout << "short " << sizeof(d) << std::endl;
  std::cout << "long " << sizeof(f) << std::endl;
  std::cout << "long long " << sizeof(g) << std::endl;
  std::cout << "char " << sizeof(e) << std::endl;
  return 0;
}
