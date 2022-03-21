#include <cstring>
#include <iostream>

int main(int argc, char** argv) {
  char c;
  int i = 0, capacity = 5;
  char* p = new char[capacity];

  while (std::cin >> c) {
    p[i] = c;
    ++i;
    if (i >= capacity) {
      capacity *= 2;
      char* temp = new char[capacity];
      for (int j = 0; j < i; ++j) {
        temp[j] = p[j];
      }
      delete[] p;
      p = temp;
    }
  }

  for (int k = 0; k < capacity; ++k) {
    std::cout << p[k];
  }
}