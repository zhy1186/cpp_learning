#include <iostream>

int compare(const int& a, const int* pb) {
  return (a >= *pb) ? a : *pb;
}

int main(){
  std::cout << "Input two nums" << std::endl;
  int a, b;
  std::cin >> a >> b;

  std::cout << compare(a, &b) << std::endl;
  return 0;
}
