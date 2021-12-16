#include <iostream>

int main(){
  int arr[10];
  for (int i = 0; i < 10; ++i){
    arr[i] = i;
  }
  
  int arr2[10];
  for (int i = 0; i < 10; ++i){
    arr2[i] = arr[i]; 
}


  for (auto i : arr){
  std::cout << arr2[i] << std::endl;
}
  return 0;
}
