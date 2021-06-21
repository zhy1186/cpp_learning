#include <iostream>
int main(){
  std::cout << "Enter two numbers:" << std::endl;
  int a, b;
  std::cin >> a >> b;
  if (a <= b){
    for (; a <= b; ++a){
      std::cout << a << std::endl;
    }
  }
  else{
    while(a >= b){
      std::cout << a << std::endl;
      --a;

    }
  }
  return 0;
}
