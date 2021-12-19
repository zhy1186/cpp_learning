#include <iostream>
#include <string>
#include <vector>

int main(){
  std::vector<std::string> scores = {"D", "C", "B", "A", "F"};

  int score = 100;
  std::string grade{};
  if (score == 100){
    grade = "A++";
  }
  else{
    if(score >= 60){
      grade = scores[(score - 60) / 10];
      if (score % 10 <= 3){
        grade += "-";
      }
      if (score % 10 >= 7){
        grade += "+";
      }
    }
    else{
      grade = scores[scores.size() - 1];
    }
  }
  std::cout << grade << std::endl;
  return 0;
}
