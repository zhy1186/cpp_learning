#include <iostream>

class IfThenElse {
 public:
  IfThenElse(int n) : num(n) {}
  int operator()(int x, int y, int z) {
    if (x == num) {
      return y;
    } else {
      return z;
    }
  }

 private:
  int num;
};

int main(int argc, char** argv) {
  IfThenElse test(10);
  std::cout << test(10, 1111, 2222) << std::endl;
  return 0;
}
