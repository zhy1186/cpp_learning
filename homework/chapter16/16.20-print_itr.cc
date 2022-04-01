#include <iostream>
#include <list>
#include <vector>

template <typename T>
inline void print(T& con) {
  for (auto iter = con.begin(); iter != con.end(); ++iter) {
    std::cout << *iter << std::endl;
  }
}

int main(int argc, char** argv) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(vec);
  return 0;
}
