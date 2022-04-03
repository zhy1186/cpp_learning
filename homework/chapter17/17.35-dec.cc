#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, char** argv) {
  std::cout << std::hexfloat << std::uppercase << std::sqrt(2.0) << std::endl;

  double a = 298.1408, b = 10000.148848, c = 10040.19199, d = 3.1,
         e = 9.2058947;
  std::cout << std::nouppercase << std::defaultfloat << std::setprecision(15)
            << std::left << std::setw(20) << a << std::endl
            << b << std::endl
            << c << std::endl
            << d << std::endl
            << e << std::endl;
}
