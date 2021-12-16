#include <iostream>
#include <iterator>

int main(){
  int arr1[10] = {1, 2, 3};
  int arr2[10] = {1, 2, 3};
  bool result = 1;

  for(int i = 0; i < 10; ++i){
    result *= (arr1[i] == arr2[i]);
  }

  if(result){
  std::cout << "arr1 equals arr2" << std::endl;
  return 0;
}
  std::cout << "arr1 not equals to arr2" << std::endl;
  return 0;
}
