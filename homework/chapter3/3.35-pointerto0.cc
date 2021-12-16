#include <iostream>
#include <iterator>

int main(){
  int arr[10];
  auto pbegin = std::begin(arr);
  auto pend = std::end(arr);
 
  for(; pbegin != pend; pbegin ++){
    *pbegin = 0;
  }

  for (auto& i : arr){
    std::cout << i << std::endl;
  }
}
