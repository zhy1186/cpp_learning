#include  <iostream>

int main(){
  int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  for (auto& p : arr){
    for (auto& q : p){
      std::cout << q << std::endl;
    }
  }
  return 0;
}
