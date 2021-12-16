#include <iostream>
#include <iterator>

int main(){
  int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8},{9, 10, 11, 12}};

  std::cout << "----------" << std::endl;
  for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 4; ++j){
      std::cout << arr[i][j] << std::endl;
    }
  }
  
  std::cout << "----------" << std::endl;
  for (int (&a)[4] : arr){
    for (auto& b : a){
      std::cout << b << std::endl;
    }
  }

  std::cout << "----------" << std::endl;
  for (int (*p)[4] = std::begin(arr); p != std::end(arr); ++p){
    for (int (*q) = std::begin(*p); q != std::end(*p); ++q){
      std::cout << *q << std::endl;
    }
  }
}
