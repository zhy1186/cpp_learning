#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "at: " << vec.at(0) << "\tidx: " << vec[0]
            << "\tfront: " << vec.front() << "\tbegin: " << *vec.begin()
            << std::endl;

  std::vector<int> void_vec{};
  std::cout << "at: "
            << " "
            << "\tidx: " << void_vec[0] << "\tfront: "
            << ""
            << "\tbegin: "
            << "" << std::endl;
}
