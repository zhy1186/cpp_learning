#include <algorithm>
#include <iostream>
#include <vector>

class Foo {
 public:
  Foo() = default;
  Foo(std::vector<int> ivec);
  Foo sorted() &&;
  Foo sorted() const &;
  using comp = bool(const int &, const int &);
  Foo sorted(comp *) &&;
  Foo sorted(comp *) const &;

 private:
  std::vector<int> data;
};

Foo::Foo(std::vector<int> ivec) : data(ivec) {}

Foo Foo::sorted() && {
  std::sort(data.begin(), data.end());
  std::cout << "Foo Foo::sorted() && " << std::endl;
  return *this;
}

Foo Foo::sorted() const & {
  Foo ret(*this);
  std::sort(ret.data.begin(), ret.data.end());
  std::cout << "Foo Foo::sorted() const & " << std::endl;
  return ret;
}

Foo Foo::sorted(comp *cmp) && {
  std::sort(data.begin(), data.end(), cmp);
  std::cout << "Foo Foo::sorted(comp *cmp) && " << std::endl;
  return *this;
}

Foo Foo::sorted(comp *cmp) const & {
  Foo ret(*this);
  std::sort(ret.data.begin(), ret.data.end(), cmp);
  std::cout << "Foo Foo::sorted(comp *cmp) && " << std::endl;
  return ret;
}

int main(int argc, char **argv) {
  std::vector<int> ivec{1, 6, 3, 6, 9, 3, 0, 4, 5};
  Foo test(ivec);
  test.sorted();  // call Foo Foo::sorted() const &

  test.sorted().sorted();

  return 0;
}
