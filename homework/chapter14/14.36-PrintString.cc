#include <iostream>
#include <string>
#include <vector>

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
  std::vector<std::string> vec_str{};

  auto rtn = input_string();
  while (rtn != "") {
    vec_str.push_back(rtn);
    rtn = input_string();
  }

  for (auto i : vec_str) {
    std::cout << i << std::endl;
  }

  return 0;
}
