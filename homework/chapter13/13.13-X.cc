#include <iostream>
#include <vector>

struct X {
  X() { std::cout << "X()" << std::endl; }
  X(const X&) {
    std::cout << "X(const X&)" << std::endl;
    std::cout << "XXXXXXXXXX   " << number << "   XXXXXXXXXX" << std::endl;
  }
  X& operator=(const X& rhs) {
    number = rhs.number;
    std::cout << "operator=(const X& rhs)" << std::endl;
    return *this;
  }
  ~X() { std::cout << "~X()" << std::endl; }
  int number;
};

void test_X(X a) { std::cout << "test_X(X a)" << std::endl; }

void test_Xr(X& a) { std::cout << "test_Xr(X& a)" << std::endl; }

std::vector<X> test_X_vec(X& a, X& b) {
  std::vector<X> vec{};
  vec.push_back(a);
  vec.push_back(b);
  // std::cout << vec.capacity() << std::endl;
  return vec;
}

int main(int argc, char** argv) {
  X test1, test2, test3, test4;
  test1.number = 1;
  test2.number = 2;
  test3.number = 3;
  test4.number = 4;

  std::cout << "==========" << std::endl;
  std::cout << "call test_X: " << std::endl;
  test_X(test1);
  std::cout << "==========" << std::endl;

  std::cout << "==========" << std::endl;
  std::cout << "call test_Xr: " << std::endl;
  test_Xr(test2);
  std::cout << "==========" << std::endl;

  std::cout << "==========" << std::endl;
  std::cout << "call test_X_vec: " << std::endl;
  test_X_vec(test3, test4);
  std::cout << "==========" << std::endl;
}
