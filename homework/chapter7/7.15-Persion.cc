#include "include/Person.h"

int main() {
  Person person_default;
  print(std::cout, person_default);

  Person person_insert("abc", "def");
  print(std::cout, person_insert);
  
  return 0;
}
