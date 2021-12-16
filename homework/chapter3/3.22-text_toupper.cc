#include <vector>
#include <string>
#include <iostream>
#include <cctype>

int main(){
  std::vector<std::string> text{};

  for (auto it = text.begin(); it != text.end() && !it -> empty(); ++it){
    for (auto itr = it->begin(); itr != it -> end() ; ++itr){
      *itr = toupper(*itr);
    }
  }

  return 0;
}
