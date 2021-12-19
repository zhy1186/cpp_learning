#include <iostream>

int main(){
  std::cout << "Input two int numbers:" << std::endl;
  
  double num1, num2;
  std::cin >> num1 >> num2;

  double result = num1 / num2;
  std::cout << result << std::endl;
  
  return 0;
}
