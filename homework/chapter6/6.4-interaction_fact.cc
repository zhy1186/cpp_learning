#include <iostream>

int fact(int val){
  int ret = 1;
  while(val > 1){
    ret *= val -- ;
  }
  return ret;
}

int main(){
  std::cout << "Input a number" << std::endl;
  int inp;
  std::cin >> inp;
  std::cout << fact(inp) << std::endl;
  
  return 0;
}
