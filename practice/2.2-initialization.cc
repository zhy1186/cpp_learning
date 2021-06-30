#include <iostream>
int main(){
  long double ld = 3.1415926535;
  int a{ld}, b = {ld};
  int c(ld), d = ld;
  std::cout << a << '\t' << b << '\t' << c << '\t' << d << std::endl;
  return 0;
}
