#include <iostream>
#include <string>

int main(){
  std::string input;
  while(std::cin >> input){
    for (std::string::size_type idx; idx < input.size(); ++idx)
      input[idx] = 'X';
    std::cout << input << std::endl;
  }
  return 0;
}
