#include <iostream>
#include <string>
#include <cctype>

int main(){
  std::string input, output;
  while (std::cin >> input){
    for (auto& c : input){
      if(ispunct(c)){
        continue;
      }else{
      output += c;
      }
    }
    std::cout << output << std::endl;
  }
  return 0;
}
