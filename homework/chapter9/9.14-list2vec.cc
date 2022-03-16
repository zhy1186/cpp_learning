#include <iostream>
#include <list>
#include <string>
#include <vector>

int main(int argc, char** argv) {
  char* pword1 = "abcde";
  char* pword2 = "fghij";
  char* pword3 = "klmno";

  std::list<char*> list_char{pword1, pword2, pword3};

  std::vector<std::string> vec_string(list_char.begin(), list_char.end());
}
