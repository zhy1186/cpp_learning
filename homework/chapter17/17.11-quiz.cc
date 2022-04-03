#include <bitset>
#include <iostream>

template <unsigned N>
class Quiz {
 public:
  void set(int number, bool answer) { quiz_.set(number - 1, answer); }

  std::ostream& output(std::ostream& os) {
    os << quiz_;
    return os;
  }

 private:
  std::bitset<N> quiz_;
};

int main(int argc, char** argv) {
  Quiz<10> test;
  test.set(8, 1);
  test.set(9, 1);

  test.output(std::cout);
}