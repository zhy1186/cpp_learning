#include <iostream>
int main(){
  int grade = 74;
  std::string final = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : (grade < 75) ? "low pass" : "pass";
  std::cout << final;
  return 0;
}
