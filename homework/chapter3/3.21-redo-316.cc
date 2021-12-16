#include <iostream>
#include <string>
#include <vector>

int main(){
  std::vector<int> v2(10);
  for (auto i = v2.begin(); i != v2.end(); ++i){
    std::cout << *i << std::endl;
  }

  std::cout << "----------" << std::endl;

  std::vector<int> v3(10,42);
  for (auto i = v3.begin(); i != v3.end(); ++i){
    std::cout << *i << std::endl;
  }

  std::cout << "----------" << std::endl;

  std::vector<int> v4{10};
  for(auto i = v4.begin(); i != v4.end(); ++i){
  std::cout << *i << std::endl;
}

  std::cout << "----------" << std::endl;

  std::vector<int> v5{10,42};
  for(auto i = v5.begin(); i != v5.end(); ++i){
  std::cout << *i << std::endl;
}

  std::cout << "----------" << std::endl;

  std::vector<std::string> v6(10);
  for (auto i = v6.begin(); i != v6.end(); ++i){
  std::cout << *i << std::endl;
}

  std::cout << "----------" << std::endl;

  std::vector<std::string> v7{10, "hi"};
  for (auto i = v7.begin(); i != v7.end(); ++i){
  std::cout << *i << std::endl;
}

  std::cout << "----------" << std::endl;

  return 0;
}
