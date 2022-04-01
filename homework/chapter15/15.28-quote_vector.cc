#include <iostream>
#include <string>
#include <vector>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string& book, double sales_price)
      : book_no_(book), price_(sales_price) {}

  std::string isbn() const { return book_no_; }
  void debug() const {
    std::cout << "book_no_:" << book_no_ << "\tprice_:" << price_ << std::endl;
  }

  virtual double net_price(std::size_t n) const { return n * price_; }
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

class Disc_quote : public Quote {
 public:
  Disc_quote() = default;
  Disc_quote(const std::string& book, double price, std::size_t qty,
             double disc)
      : Quote(book, price), quantity_(qty), discount_(disc) {}
  virtual double net_price(std::size_t) const = 0;

 protected:
  std::size_t quantity_ = 0;
  double discount_ = 0.0;
};

class Bulk_quote : public Disc_quote {
  using Disc_quote::Disc_quote;

 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string& book, double price, std::size_t qty,
             double disc)
      : Disc_quote(book, price, qty, disc) {}
  double net_price(std::size_t) const override;
};

double Bulk_quote::net_price(std::size_t n) const {
  if (n > quantity_)
    return (1 - discount_) * n * price_;
  else
    return n * price_;
}

double print_total(std::ostream& os, const Bulk_quote item, std::size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

int main(int argc, char** argv) {
  std::vector<Quote> quote_vec{};
  quote_vec.push_back(Quote("quote", 50.0));
  quote_vec.push_back(Bulk_quote("bulk_quote", 50.0, 3, 0.2));

  print_total(std::cout, quote_vec[0], 10);
  print_total(std::cout, quote_vec.back(), 10);

  return 0;
}
