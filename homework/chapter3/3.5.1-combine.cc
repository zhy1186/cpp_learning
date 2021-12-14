#include <iostream>
#include <string>
int main(){
  std::string input, sum;
  while(std::cin >> input){
    sum += input;
  }
  std::cout << sum;

  return 0;
}
