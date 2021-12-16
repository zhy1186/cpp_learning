#include <iostream>
#include <vector>

int main(){
  std::vector<int> vec1{};
  for (int i = 0; i < 10; ++i){
    vec1.push_back(i);
  }

  std::vector<int> vec2 = vec1;
  for (auto& i : vec2){
    std::cout << i << std::endl;
  }

  return 0;
}
