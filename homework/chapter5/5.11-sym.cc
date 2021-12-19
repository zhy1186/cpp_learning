#include <iostream>

int main(){
  char i{};
  int aNum, eNum, iNum, oNum, uNum, blankNum, tabNum, enterNum;
  aNum = eNum = iNum = oNum = uNum = blankNum = tabNum = enterNum = 0;

  while((i = std::cin.get()) != '#'){
      if (i == 'a') ++ aNum;
      if (i == 'e') ++ eNum;
      if (i == 'i') ++ iNum;
      if (i == 'o') ++ oNum;
      if (i == 'u') ++ uNum;
      if (i == '\n') ++ enterNum;
      if (i == '\t') ++ tabNum;
      if (i == ' ') ++ blankNum;
  }
  std::cout << aNum << std::endl << eNum << std::endl << iNum << std::endl << oNum << std::endl << uNum << std::endl << enterNum << std::endl << tabNum << std::endl << blankNum << std::endl;
  return 0;
}
