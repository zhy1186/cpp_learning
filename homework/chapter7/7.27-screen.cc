#include "include/Screen.h"

int main(int argc, char** argv) {
  Screen myScreen (5, 5, 'X');
  myScreen.move(4, 0).set('#').display(std::cout);
  std::cout << std::endl;
  myScreen.display(std::cout);
  std::cout << std::endl;

  return 0;
}
