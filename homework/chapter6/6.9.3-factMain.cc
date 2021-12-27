#include <iostream>

#include "6.9.2-Chapter6.h"

int main(){
  std::cout << "Input a number" << std::endl;
  int inp;
  std::cin >> inp;
  std::cout << fact(inp) << std::endl;
  
  return 0;
}
