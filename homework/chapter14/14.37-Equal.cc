#include <algorithm>
#include <iostream>
#include <vector>

class Equal {
 public:
  Equal(int num) : num_(num){};
  bool operator()(int a) { return (a == num_); }

 private:
  int num_;
};

int main() {
  std::vector<int> vi = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5,
                         8, 9, 7, 9, 3, 2, 3, 8, 4, 6};
  std::replace_if(vi.begin(), vi.end(), Equal(3), 99999);

  for (auto i : vi) {
    std::cout << i << std::endl;
  }
  return 0;
}
