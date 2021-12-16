#include <iostream>
#include <vector>
#include <iterator>

int main(){
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec(std::begin(arr), std::end(arr));

  for (auto& i : vec){
    std::cout << i << std::endl;
  }  
  return 0;
}
