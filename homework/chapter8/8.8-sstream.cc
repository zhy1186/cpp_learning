#include <sstream>
#include <iostream>
#include <string>
#include <stdexcept>

std::istringstream& sstream(std::istringstream& is) {
  std::string buf;
  while (is >> buf) {
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
  std::string words;
  std::getline(std::cin, words);
  std::istringstream is(words);

  auto& iss = sstream(is);
  return 0;
}
