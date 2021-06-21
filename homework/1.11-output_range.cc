#include <iostream>
int main(){
  std::cout<<"Input two int numbers"<<std::endl;
  int a,b;
  std::cin>>a>>b;
  while (a <= b){
    std::cout<<a<<std::endl;
    ++a;
  }
  while (a >= b){
    std::cout<<a<<std::endl;
    --a;
  }
  return 0;
}
