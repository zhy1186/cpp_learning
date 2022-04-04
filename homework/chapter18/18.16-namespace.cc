#include <iostream>

namespace Exercise {
int ivar = 0;
double dvar = 0;
const int limit = 1000;
}  // namespace Exercise

int ivar = 0;

void manip() {
  // using Exercise::dvar;
  // using Exercise::ivar;
  // using Exercise::limit;
  using namespace Exercise;
  double dvar = 3.1416;
  int iobj = limit + 1;
  std::cout << iobj << std::endl;
  std::cout << (++ivar) << std::endl;
  std::cout << (++::ivar) << std::endl;
}

int main(int argc, char** argv) {
  manip();
  return 0;
}
