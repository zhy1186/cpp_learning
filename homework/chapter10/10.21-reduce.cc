#include <iostream>

int main() {
  int ttl = 9;
  auto f = [&ttl]() -> bool {
    if (ttl == 0) {
      return false;
    } else {
      --ttl;
      return true;
    }
  };

  for (int i = 0; i < 10; ++i) {
    std::cout << f() << std::endl;
  }
  return 0;
}
