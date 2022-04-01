#include <iostream>
#include <string>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string& book, double sales_price)
      : book_no_(book), price_(sales_price) {}

  std::string isbn() const { return book_no_; }

  virtual net_price(std::size_t n) const { return n * price_; }
  virtual ~Quote() = default;

 protected:
  double price_ = 0.0;

 private:
  std::string book_no_;
};

double print_total(std::ostream& os, const Quote item, std::size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}
