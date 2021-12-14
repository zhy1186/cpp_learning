#include <iostream>
int main(){
  int input_value;
  std::cin >> input_value;

  double d = 3.14;
  int i = {d};
  int a{d};
  int b(d);
  int c = d;

  double salary, wage = 9999.99;
  std::cout << salary << '\t' << wage << std::endl;
  int j = 3.14;
  return 0;
}
