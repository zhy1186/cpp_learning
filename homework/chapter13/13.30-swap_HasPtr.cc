#include <algorithm>
#include <iostream>
#include <string>

class HasPtr {
  friend void swap(HasPtr &lhs, HasPtr &rhs);

 public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
  HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
  HasPtr &operator=(const HasPtr &);
  std::string get_str() { return *ps; }
  ~HasPtr();

 private:
  std::string *ps;
  int i;
  std::size_t *use;
};

HasPtr::~HasPtr() {
  if (--*use == 0) {
    delete ps;
    delete use;
  }
}

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  ++*rhs.use;
  if (--*use == 0) {
    delete ps;
    delete use;
  }
  ps = rhs.ps;
  i = rhs.i;
  use = rhs.use;
  return *this;
}

void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  std::cout << __FUNCTION__ << std::endl;
}

int main() {
  HasPtr a("aaa"), b("bbb");
  swap(a, b);

  std::cout << b.get_str() << std::endl;
}
