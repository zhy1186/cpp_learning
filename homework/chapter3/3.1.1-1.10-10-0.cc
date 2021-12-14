#include <iostream>

using std::cout;
using std::cin, std::endl;  // valid for C++ 17
int main(){
  int i = 10;
  while(i >= 0){
    cout << i << endl;
    --i;
  }
  return 0;
}
