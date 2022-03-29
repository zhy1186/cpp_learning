#include <iostream>
#include <string>

class PrintString {
 public:
  PrintString(std::ostream& o = std::cout, char c = ' ') : os(o), sep(c) {}
  void operator()(const std::string& s) const { os << s << sep; }

 private:
  std::ostream& os;
  char sep;
};

class InputString {
 public:
  InputString(std::istream& is = std::cin) : is_(is) {}
  std::string operator()() {
    std::string word;
    if (std::getline(is_, word)) {
      return word;
    } else {
      word = "";
      return word;
    }
  }

 private:
  std::istream& is_;
};

int main(int argc, char** argv) {
  InputString input_string;
  auto rtn = input_string();
  std::cout << "==========" << std::endl;
  std::cout << rtn << std::endl;
  return 0;
}
