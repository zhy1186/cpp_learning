#include <iostream>
#include <vector>

int main(){
  std::vector<int> vec1 = {1,2,3};
  std::vector<int> vec2 = {1,2,3};

  std::vector<int>::iterator itr1 = vec1.begin();
  std::vector<int>::iterator itr2 = vec2.begin();

  if (vec1.size() != vec2.size()){
    std::cout << "not equal!" << std::endl;
    return 0;
  }


  bool result = 1;
  for (int i = 0; i < vec1.size(); ++i){
    result *= ((*itr1++) == (*itr2++));
  }

  if(result){
  std::cout << "equal" << std::endl;
  return 0;
}

  std::cout << "not equal" << std::endl;
}
