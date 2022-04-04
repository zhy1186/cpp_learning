#include <cstddef>
#include <cstdlib>
#include <stdexcept>

void* operator new(std::size_t size) {
  if (void* mem == std::malloc(size)) {
    return mem;
  } else {
    return std::bad_alloc();
  }
}

void operator delete(void* mem) noexcept { std::free(mem); }
