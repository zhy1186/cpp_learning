#include <vector>
#include <iostream>
int main(){
  std::vector<int> nums{};
  int num;

  while(std::cin >> num){
    nums.push_back(num);
  }

  for (int i = 0; i < nums.size(); ++i){
    std::cout << "Sum up of " << i + 1 << " th and " << nums.size() - i << " th number is " <<  nums[i] + nums[nums.size() - i -1] << std::endl; 
  }
}
