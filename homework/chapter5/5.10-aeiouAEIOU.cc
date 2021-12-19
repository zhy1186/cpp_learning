#include <iostream>
#include <string>

int main(){
  std::string inp{};
  int aNum, eNum, iNum, oNum, uNum;
  aNum = eNum = iNum = oNum = uNum = 0;

  while(std::cin >> inp){
    for (auto& i: inp){
      switch(i){
        case 'A':
        case 'a':
          ++ aNum;
          break;
        case 'E':
        case 'e':
          ++ eNum;
          break;
        case 'I':
        case 'i':
          ++ iNum;
          break;
        case 'O':
        case 'o':
          ++ oNum;
          break;
        case 'U':
        case 'u':
          ++ uNum;
          break;
      }
    }
  }
  std::cout << aNum << std::endl << eNum << std::endl << iNum << std::endl << oNum << std::endl << uNum << std::endl;
  return 0;
}
