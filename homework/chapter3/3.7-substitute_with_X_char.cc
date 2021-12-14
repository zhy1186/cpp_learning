#include <iostream>
#include <string>

int main(){
  std::string input;
  while(std::cin >> input){
    for (char& c : input){
      c = 'X';
    }
  std::cout << input << std::endl;
  }
  return 0;
}
