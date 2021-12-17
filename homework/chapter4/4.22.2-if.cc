#include <iostream>
int main(){
  int grade = 88;
  std::string final{};
  if (grade > 90) final = "high pass";
  if (grade > 75) final = "pass";
  if (grade >= 60) final = "low pass";
  if (grade < 60) final = "fail";
  std::cout << final << std::endl;
}
