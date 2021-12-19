#include <iostream>
#include <stdexcept>

int main(){
  std::cout << "Input two int numbers:" << std::endl;
  
  double num1, num2;
  std::cin >> num1 >> num2;

  try{
    if(num2 == 0)
      throw std::runtime_error("divide number cannot be 0.");
  } catch(std::runtime_error err){
    std::cout << err.what() << "Input two numbers again ?" << std::endl;
    std::cin >> num1 >> num2;    
  }

  double result = num1 / num2;
  std::cout << result << std::endl;
  
  return 0;
}
