#include <iostream>
#include <vector>

int main(){
  std::vector<int> vec = {1, 2, 3, 4, 5};
  
  int arr[5];
  int cnt = 0;

  for (auto& i : vec){
  arr[cnt] = i;
  ++cnt;
}

  for (int i = 0; i < 5 ; ++i){
  std::cout << arr[i] << std::endl;
}

  return 0;
}
