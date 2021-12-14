#include <vector>
#include <iostream>
int main(){
  std::vector<int> nums{};
  int num;

  while(std::cin >> num){
    nums.push_back(num);
  }

  for (int i = 0; i < nums.size() - 1; ++i){
    std::cout << "Sum up of " << i + 1 << " th and " << i + 2 << " th number is " <<  nums[i] + nums[i + 1] << std::endl; 
  }
}
