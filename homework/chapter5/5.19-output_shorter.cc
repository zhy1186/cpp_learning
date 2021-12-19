#include <iostream>
#include <string>

int main(){
  do {
    std::cout << "input two string:" << std::endl;
    std::string s1, s2;

    std::cin >> s1 >> s2;
    std::cout << ((s1.size() >= s2.size()) ? s2 : s1) << std::endl;
  } while(std::cin);
  
  return 0;
}
