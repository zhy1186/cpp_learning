#include <vector>
#include <iostream>
int main(){
  std::vector<int> nums{};
  int num;

  while(std::cin >> num){
    nums.push_back(num);
  }

  for (auto i = nums.begin(); i != nums.end() - 1; ++i){
    std::cout << "Sum up " <<  *i + *(i + 1) << std::endl; 
  }
}
