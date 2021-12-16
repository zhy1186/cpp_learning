#include <iostream>
#include <iterator>

using int_array4 = int[4];
using int_array3 = int[3];

int main(){
  int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8},{9, 10, 11, 12}};

  for (int_array4 *p = std::begin(arr); p != std::end(arr); ++p){
    for (int *q = std::begin(*p); q != std::end(*p); ++q){
      std::cout << *q << std::endl;
    }
  }
}
