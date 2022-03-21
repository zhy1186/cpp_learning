#include <iostream>
#include <memory>
#include <vector>

std::vector<int>* rtn_new_vector() {
  std::vector<int>* vec = new std::vector<int>;
  return vec;
}

std::vector<int>* input() {
  int num;
  auto vec = rtn_new_vector();
  while (std::cin >> num) {
    vec->push_back(num);
  }
  return vec;
}

void output(std::vector<int>* vec) {
  for (auto i : *vec) {
    std::cout << i << std::endl;
  }
  delete vec;
  return;
}

int main(int argc, char** argv) {
  auto test = input();
  output(test);
  return 0;
}
