#include <iostream>
#include <list>
#include <vector>

template <typename T>
inline void print(T& con) {
  for (typename T::size_type i = 0; i != con.size(); ++i) {
    std::cout << con[i] << std::endl;
  }
}

int main(int argc, char** argv) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print(vec);
  return 0;
}
