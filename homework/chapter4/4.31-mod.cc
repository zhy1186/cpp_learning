#include <iostream>
#include <vector>


int main(){
  std::vector<int> ivec = {1,2,3,4,5,6,7,8,9};
  std::vector<int>::size_type cnt = ivec.size();
  for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    ivec[ix] = cnt;
  for (auto& i : ivec)
    std::cout << i << std::endl;
  return 0;
}
