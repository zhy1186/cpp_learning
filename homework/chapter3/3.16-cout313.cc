#include <iostream>
#include <string>
#include <vector>

int main(){
  std::vector<int> v2(10);
  for (auto & i : v2){
    std::cout << i << std::endl;
  }

  std::cout << "----------" << std::endl;

  std::vector<int> v3(10,42);
  for (auto& i : v3){
    std::cout << i << std::endl;
  }

  std::cout << "----------" << std::endl;

  std::vector<int> v4{10};
  for(auto &i : v4){
  std::cout << i << std::endl;
}

  std::cout << "----------" << std::endl;

  std::vector<int> v5{10,42};
  for(auto &i : v5){
  std::cout << i << std::endl;
}

  std::cout << "----------" << std::endl;

  std::vector<std::string> v6(10);
  for (auto &i : v6){
  std::cout << i << std::endl;
}

  std::cout << "----------" << std::endl;

  std::vector<std::string> v7{10, "hi"};
  for (auto& i : v7){
  std::cout << i << std::endl;
}

  std::cout << "----------" << std::endl;

  return 0;
}
