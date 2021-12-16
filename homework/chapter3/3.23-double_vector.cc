#include <iostream>
#include <vector>

int main(){
  std::vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

  for (auto itr = nums.begin(); itr != nums.cend(); ++itr){
    *itr = 2 * (*itr);
  }

  for (auto num : nums){
    std::cout << num << std::endl;
  }
  return 0;
}
