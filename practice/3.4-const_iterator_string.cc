#include <string>
#include <iostream>

int main(){
  const std::string test = "hello";

  std::string::iterator it1;
  std::string::const_iterator it2;

  it1 = test.begin();
  it2 = test.begin();

  std::cout << "it1 " << *it1 << std::endl << "it2 " << *it2 << std::endl;

  return 0;
  
}
