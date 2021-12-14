#include <vector>
#include <iostream>

int main(){
  std::vector<int> input;

  int temp;
  while(std::cin>>temp){
    input.push_back(temp);
  }
  return 0;
}
