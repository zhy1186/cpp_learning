#include <string>
#include <vector>
#include <iostream>
#include <cctype>

int main(){
  std::vector<std::string> words{};
  std::string word{};

  while(std::cin >> word){
    for (auto &i : word){
      i = toupper(i);
    }
    words.push_back(word);
  }

  for (auto &i : words){
    std::cout << i << std::endl;
  }

  return 0;
}
