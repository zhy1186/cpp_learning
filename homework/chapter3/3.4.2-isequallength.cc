#include <iostream>
#include <string>

int main(){
  std::string input1, input2;
  std::cin >> input1 >> input2;
  std::string larger = input1.size() > input2.size() ? input1 : input2;
  std::cout << larger << std::endl;

  return 0;
}
