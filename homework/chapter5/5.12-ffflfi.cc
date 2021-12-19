#include <iostream>
#include <string>

int main(){
  char inp{};
  char last{};
  int aNum, eNum, iNum, oNum, uNum, ffNum, flNum, fiNum;
  aNum = eNum = iNum = oNum = uNum = ffNum = flNum = fiNum = 0;

  while(std::cin >> inp){
      switch(inp){
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
          if (last == 'f') ++ fiNum;
          break;
        case 'O':
        case 'o':
          ++ oNum;
          break;
        case 'U':
        case 'u':
          ++ uNum;
          break;
        case 'f':
          if (last == 'f') ++ ffNum;
          break;
        case 'l':
          if (last == 'f') ++ flNum;
          break; 
     }
     last = inp;
  }
  std::cout << aNum << std::endl << eNum << std::endl << iNum << std::endl << oNum << std::endl << uNum << std::endl << ffNum << std::endl << flNum << std::endl << fiNum << std::endl;
  return 0;
}
