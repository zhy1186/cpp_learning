#include <iostream>
#include <cstring>

int main(){
  char arr1[16] = "abcd";
  char arr2[4] = "efg";
  char large_arr[32] = "";

  arr1[15] = '\0';
  arr2[3] = '\0';
  large_arr[31] = '\0';

  std::strcat(arr1, arr2); 
  std::strcpy(large_arr, arr1);

  std::cout <<large_arr;

  return 0;
}
