#include <iostream>
#include <vector>

void revec(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
  if(begin == end) {
    std::cout << "----------" << std::endl;
    return;
  }
  std::cout << *begin << std::endl;
  #ifndef NDEBUG
    std::cout << "size of vector now is : " << end - begin << std::endl;
  #endif
  return revec(++begin, end);
}

int main() {
  std::vector<int> output {1, 2, 3, 5, 8, 13, 21};
  revec(output.cbegin(), output.cend());
  return 0;
}
