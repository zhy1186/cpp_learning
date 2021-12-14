#include <vector>
#include <iostream>

int main(){
  std::vector<std::string> input;

  std::string temp;
  while(std::cin>>temp){
    input.push_back(temp);
  }
  return 0;
}
