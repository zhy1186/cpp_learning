#include <iostream>
#include <memory>
#include <string>

int main(int argc, char** argv) {
  std::allocator<std::string> alloc;
  int size = 10;
  const auto begin = alloc.allocate(size);
  std::string s;
  auto curr = begin;

  while (std::cin >> s && curr != begin + size) {
    alloc.construct(curr++, s);
  }

  while (curr != begin) {
    std::cout << *--curr << std::endl;
    alloc.destroy(curr);
  }
  alloc.deallocate(begin, size);

  return 0;
}
