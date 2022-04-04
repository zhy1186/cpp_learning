#include <iostream>
#include <typeinfo>

class Base {};

class Derived : public Base {};

int main(int argc, char** argv) {
  int arr[10];
  Derived d;
  Base* p = &d;
  int r = 42;
  int& test = r;

  std::cout << typeid(42).name() << std::endl;
  std::cout << typeid(42.123).name() << std::endl;
  std::cout << typeid(arr).name() << std::endl;
  std::cout << typeid(std::string).name() << std::endl;
  std::cout << typeid(d).name() << std::endl;
  std::cout << typeid(p).name() << std::endl;
  std::cout << typeid(Base()).name() << std::endl;
  std::cout << typeid(test).name() << std::endl;
}
