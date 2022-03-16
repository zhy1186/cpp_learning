#include <iostream>
#include <vector>

std::string fun1(std::string s, const std::string oldVal,
                 const std::string newVal) {
  auto itr_s = s.begin();
  auto itr_old = oldVal.begin();

  while (itr_s != s.end()) {
    if (*itr_s == *itr_old) {
      ++itr_old;
    } else {
      itr_old = oldVal.begin();
    }
    ++itr_s;

    if (itr_old == oldVal.end()) {
      itr_s = s.erase(itr_s - oldVal.size(), itr_s);
      itr_s = s.insert(itr_s, newVal.begin(), newVal.end());
    }
  }
  return s;
}

int main(int argc, char** argv) {
  std::string test = "aaaaathoaaaaathoaaaaaaathoaaatho";
  std::string rtn = fun1(test, "tho", "though");
  std::cout << rtn << std::endl;

  return 0;
}
