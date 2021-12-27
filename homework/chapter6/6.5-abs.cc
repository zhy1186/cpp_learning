#include <iostream>

double abs(double var){
  return var > 0 ? var : -var;
}

int main(){
  int test = 6;
  std::cout << abs(test);
  return 0;
}
