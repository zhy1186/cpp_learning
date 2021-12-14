#include <iostream>
#include <string>

int main(){
  std::string input;
  while(std::cin >> input){
    std::string::size_type idx;
    while(idx < input.size()){
      input[idx] = 'X';
      ++idx;
    }
  std::cout << input << std::endl;
  }
  return 0;
}
