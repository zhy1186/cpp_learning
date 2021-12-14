#include <iostream>
int main(){
  int a = 0, sum = 0;
  std::cout << "Enter a series of numbers:" << std::endl;
  while(std::cin >> a)
    sum += a;
  std::cout << "Sum is " << sum << std::endl;
  return 0;
}
