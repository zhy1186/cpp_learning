#include <iostream>
#include <string>

class Employee {
 public:
  Employee() = default;
  Employee(std::string& name) : name_(name) { id_ = id_increment_++; }
  Employee(const Employee&) = delete;
  Employee& operator=(const Employee&) = delete;

 private:
  static int id_increment_;
  int id_;
  std::string name_;
};