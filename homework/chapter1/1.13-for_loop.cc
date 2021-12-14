#include <iostream>
int main(){
  std::cout << "practice 1.9"<<std::endl;
  int sum;
  for (int i = 50;i <= 100;++i){
    sum += i;
  }
  std::cout << "sum from 50 to 100 is: " << sum << std::endl;

  std::cout << "practice 1.10"<<std::endl;
  for (int i = 10;i >= 0; --i){
    std::cout << i << std::endl;
  }

  std::cout << "practice 1.11"<<std::endl;
  std::cout << "Input 2 intnumbers:"<<std::endl;
  int a, b;
  std::cin>>a>>b;
  for (; a >= b; a--){
    std::cout << a << std::endl;
  }
  for (; a <= b; a++){
    std::cout << a << std::endl;
  }
  return 0;
}
