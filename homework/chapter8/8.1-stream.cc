#include <iostream>
#include <string>
#include <stdexcept>

std::istream& stream(std::istream& is) {
  int buf;
  while (is >> buf, !is.eof()) {
  	if (is.bad()) {
  	  throw std::runtime_error("is badbit");
  	} if(is.fail()) {
  	  std::cerr << "Error, try again!" << std::endl;
  	  is.clear();
  	  is.ignore();
  	} else {
  	std::cout << buf << std::endl;
    }
  }
  is.clear();
  return is;
}

int main(int argc, char** argv) {
  auto& is = stream(std::cin);
  return 0;
}
