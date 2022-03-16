#include <iostream>
#include <vector>

std::string fun1(std::string s, const std::string oldVal,
                 const std::string newVal) {
  int idx_s = 0;
  int idx_old = 0;
  while (idx_s != s.size()) {
    if (s[idx_s] == oldVal[idx_old])
      ++idx_old;
    else
      idx_old = 0;

    ++idx_s;

    if (idx_old == oldVal.size()) {
      idx_old = 0;
      s.replace(idx_s - oldVal.size(), idx_s, newVal);
    }
  }
  return s;
}

int main(int argc, char** argv) {
  std::string test = "aaaaathoaaaaaaaaaathoaaaaaaaaaaaathoaaaaaaaatho";
  std::string rtn = fun1(test, "tho", "though");
  std::cout << rtn << std::endl;

  return 0;
}
