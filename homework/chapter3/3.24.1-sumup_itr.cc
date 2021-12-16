#include <vector>
#include <iostream>
int main(){
  std::vector<int> nums{};
  int num;

  while(std::cin >> num){
    nums.push_back(num);
  }

  for (auto i = nums.begin(); i != nums.end(); ++i){
    std::cout << "Sum up results " <<  (*i) + *(nums.begin() + (nums.end() - i) - 1) << std::endl; 
  }
}
