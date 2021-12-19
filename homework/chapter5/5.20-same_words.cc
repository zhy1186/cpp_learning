#include <iostream>
#include <string>

int main(){
  std::string inp{}, last{};

  while(std::cin >> inp){
    if(inp == last){
      std::cout << "Same words " << inp << std::endl;
      break;  
    }
    last = inp;
  }
  
  if (! std::cin){
      std::cout << "No same words dectected! " << std::endl;
  }
  return 0;
}
