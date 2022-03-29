#include <functional>
#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::function<int(int, int)>> binops = {
    {"+", std::plus<int>()},
    {"-", std::minus<int>()},
    {"*", std::multiplies<int>()},
    {"/", std::divides<int>()},
    {"%", std::modulus<int>()}};

int main(int argc, char** argv) {
  int a = 4, b = 8;
  std::cout << binops["+"](a, b) << std::endl;
  std::cout << binops["-"](a, b) << std::endl;
  std::cout << binops["*"](a, b) << std::endl;
  std::cout << binops["/"](a, b) << std::endl;
  std::cout << binops["%"](a, b) << std::endl;

  return 0;
}
