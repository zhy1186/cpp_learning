#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> rtn_new_vector() {
  return std::make_shared<std::vector<int>>();
}

std::shared_ptr<std::vector<int>> input() {
  auto vec = rtn_new_vector();
  int num{};
  while (std::cin >> num) {
    vec->push_back(num);
  }
  return vec;
}

void output(std::shared_ptr<std::vector<int>> vec) {
  for (auto i : *vec) {
    std::cout << i << std::endl;
  }
  return;
}

int main(int argc, char** argv) {
  auto test = input();
  output(test);
  return 0;
}
