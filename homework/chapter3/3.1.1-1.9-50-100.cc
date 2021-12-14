#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int i = 50, sum = 0;
  while(i<=100){
    sum += i;
    ++i;
  }
  cout << "Sum up 50 to 100 is: " << sum << endl;
  return 0;
}
