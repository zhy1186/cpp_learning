#include <iostream>
#include <string>

int main(){
  std::string input, input2;
  while(getline(std::cin, input2)) {
    std::cout << "One line:\n" << input2 << std::endl;
  }

  return 0;
}
