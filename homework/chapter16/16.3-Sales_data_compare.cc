#include <algorithm>
#include <iostream>

#include "include/Sales_data.h"

template <typename T>
int compare(const T& v1, const T& v2) {
  if (std::less<T>()(v1, v2)) return -1;
  if (std::less<T>()(v2, v1))
    return 1;
  else
    return 0;
}

int main(int argc, char** argv) {
  Sales_data a("aaaaa", 10, 10.0);
  Sales_data b("bbbbb", 15, 12.0);
  // std::cout << compare(a, b) << std::endl;
  return 0;
}