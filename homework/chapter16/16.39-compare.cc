#include <algorithm>
#include <iostream>
#include <string>

template <typename T>
int compare(const T& v1, const T& v2) {
  if (std::less<T>()(v1, v2)) return -1;
  if (std::less<T>()(v2, v1))
    return 1;
  else
    return 0;
}

int main(int argc, char** argv) {
  std::cout << compare<std::string>("3.0", "8.112") << std::endl;
  return 0;
}
