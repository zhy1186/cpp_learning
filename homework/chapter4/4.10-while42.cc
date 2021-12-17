#include <iostream>
int main(){
  int inp;
  while((std::cin >> inp) && (inp != 42)){
    continue;
  }
  return 0;
}
