#include <iostream>
#include <string>

int main(){
  std::string inp{};
  int aNum, eNum, iNum, oNum, uNum;
  aNum = eNum = iNum = oNum = uNum = 0;

  while(std::cin >> inp){
    for (auto &i : inp){
      if (i == 'a') ++ aNum;
      if (i == 'e') ++ eNum;
      if (i == 'i') ++ iNum;
      if (i == 'o') ++ oNum;
      if (i == 'u') ++ uNum;
    }
  }
  std::cout << aNum << std::endl << eNum << std::endl << iNum << std::endl << oNum << std::endl << uNum << std::endl;
  return 0;
}
