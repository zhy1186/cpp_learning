#include <bitset>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  std::vector<int> ivec{1, 2, 3, 5, 8, 13, 21};
  std::bitset<32> bset1;
  for (auto i : ivec) {
    bset1.set(i);
  }

  std::bitset<32> bset2;
  for (std::size_t i = 0; i < bset1.size(); ++i) {
    bset2[i] = bset1[i];
  }

  std::cout << bset1.to_ullong() << '\t' << bset2.to_ullong() << std::endl;
  return 0;
}
