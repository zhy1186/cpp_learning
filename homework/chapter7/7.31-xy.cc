#include <iostream>

class X;
class Y;

class X {
private:
  Y* py;
};

class Y {
private:
  X x;
};

int main(int argc, char** argv) {
  X test_x;
  Y test_y;

  return 0;
}
