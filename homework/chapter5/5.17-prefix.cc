#include <iostream>
#include <vector>

int main(){
  std::vector<int> vec1{0, 1, 3, 2};
  std::vector<int> vec2{0, 1, 1, 2, 3, 5, 8};
  
  std::vector<int> short_vec{}, long_vec{};
  bool ret = 1;
  if(vec1.size() <= vec2.size()){
    short_vec = vec1;
    long_vec = vec2;
  }
  else{
    short_vec = vec2;
    long_vec = vec1;
  }

  for (auto itr = short_vec.begin(); itr != short_vec.end(); ++itr){
    ret *= (*itr == (long_vec[itr - short_vec.begin()]));
  }
  
  std::cout << "Is prefix ? " << ret << std::endl;
  return 0;
}
