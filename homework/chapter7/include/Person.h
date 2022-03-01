#include <string>
#include <iostream>

class Person {
friend std::istream& read(std::istream &is, Person& item);
friend std::ostream& print(std::ostream &os, const Person& item);

private:
  std::string name;
  std::string address;

public:
  Person() = default;
  Person(std::string input_name, std::string input_address) : name(input_name), address(input_address) {}

  std::string GetName() const{
    return name;
  }

  std::string GetAddress() const{
    return address;
  }
};

std::istream& read(std::istream &is, Person& item) {
  is >> item.name >> item.address;
  return is;
}

std::ostream& print(std::ostream &os, const Person& item) {
  os << item.name << '\t' << item.address;
  return os;
}
