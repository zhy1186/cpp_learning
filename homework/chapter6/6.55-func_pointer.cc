#include <iostream>
#include <vector>

typedef int func(int, int);

int sum(int a, int b){
  return (a + b);
}

int minus(int a, int b) {
  return (a - b);
}

int times(int a, int b) {
  return a * b;
}

int divide(int a, int b) {
  return a / b;
}

int main(int argc, char** argv) {
  std::vector<func*> funs{};
  int a = 5, b = 10;
  
  funs.push_back(*sum);
  funs.push_back(*minus);
  funs.push_back(*times);
  funs.push_back(*divide);
  
  for (auto& i : funs) {
  std::cout << (*i)(a, b) << std::endl;
}
  return 0;
}
