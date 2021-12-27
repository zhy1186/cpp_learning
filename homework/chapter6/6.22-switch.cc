#include <iostream>

void swap_pointer(int* &a, int* &b);

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << "Before: " << a << '\t' <<b << std::endl;
  int *pa = &a, *pb = &b;
  swap_pointer(pa, pb);
  std::cout << "After: " << *pa << '\t' << *pb << std::endl;
  return 0;
}

void swap_pointer(int* &a, int* &b){
  int* temp = a;
  a = b;
  b = temp;
  std::cout << "In " << *a << '\t' << *b << std::endl;
}
