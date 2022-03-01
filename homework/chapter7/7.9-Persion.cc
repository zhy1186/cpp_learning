#include "include/Person.h"

int main(int argc, char** argv) {
  Person person;
  read(std::cin, person);
  print(std::cout, person);
}
