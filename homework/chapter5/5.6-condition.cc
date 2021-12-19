#include <iostream>
#include <string>
#include <vector>

int main(){
  std::vector<std::string> scores = {"D", "C", "B", "A", "F"};

  int score = 86;
  std::string grade{};

  score == 100 ? (grade = "A++") : ((score >= 60) ? (grade  = scores[(score - 60) / 10]) : (grade = scores[scores.size() - -1]));
  
  std::cout << grade << std::endl;
  return 0;
}
