#include <string>
#include <iostream>

typedef std::string Type;
Type initVal();
class Exercise {
public:
  typedef double Type;
  Type setVal(Type);
  Type initVal() {return 1;};

private:
  int val;
};

Exercise::Type Exercise::setVal(Type parm) {
  val = parm + initVal();
  return val;
}

int main(int argc, char** argv) {
  Exercise e;
  
  return 0;
}
