#include <iostream>
#include <string>

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);
  friend std::istream &operator>>(std::istream &, Sales_data &);
  friend std::ostream &operator<<(std::ostream &, Sales_data &);

 public:
  Sales_data() = default;
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(const std::string &s) : Sales_data(s, 0, 0) {}
  Sales_data(std::istream &is) : Sales_data(){};
  Sales_data &operator+=(const Sales_data &);

  explicit operator std::string() const { return bookNo; };
  explicit operator double() const { return revenue; }

  std::string isbn() const { return bookNo; }

  Sales_data &combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

 private:
  inline double avg_price() const {
    if (units_sold) {
      return revenue / units_sold;
    } else {
      return 0;
    }
  }

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data &add(Sales_data &lhs, Sales_data &rhs) {
  Sales_data &sum = lhs;
  sum.combine(rhs);
  return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << "vvvvvvvvvv\n";
  os << item.bookNo << " " << item.units_sold << " " << item.revenue
     << std::endl;
  os << "^^^^^^^^^^\n";
  return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item) {
  if (is) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
  } else {
    item = Sales_data();
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, Sales_data &item) {
  os << "vvvvvvvvvv\n";
  os << item.bookNo << " " << item.units_sold << " " << item.revenue
     << std::endl;
  os << "^^^^^^^^^^\n";
  return os;
}

Sales_data &operator+(Sales_data &lhs, Sales_data &rhs) {
  Sales_data &sum = lhs;
  sum.combine(rhs);
  return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
  return combine(rhs);
}
