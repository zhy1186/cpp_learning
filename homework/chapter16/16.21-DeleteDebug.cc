#include <iostream>
#include <memory>

class DebugDelete {
 public:
  DebugDelete(std::ostream& os = std::cerr) : os(os) {}
  template <typename T>
  void operator()(T* p) const {
    os << "deleting unique_ptr" << std::endl;
    delete p;
  }

 private:
  std::ostream& os;
};

int main(int argc, char** argv) {
  std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());
  std::unique_ptr<std::string, DebugDelete> sp(new std::string, DebugDelete());
}
