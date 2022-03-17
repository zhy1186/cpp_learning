#include <numeric>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Sum of vector test is: "
            << std::accumulate(test.cbegin(), test.cend(), 0) << std::endl;

  return 0;
}
