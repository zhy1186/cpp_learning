#include <iostream>
#include <vector>

int main(){
  std::vector<unsigned> scores(11, 0);
  unsigned grade;
  
  while (std::cin >> grade){
    if(grade <= 100){
      auto itr = scores.begin() + grade / 10;
      (*itr) ++;
    }
  }
  
  for (auto itr : scores){
    std::cout << itr << std::endl;
  }

  return 0;
}
