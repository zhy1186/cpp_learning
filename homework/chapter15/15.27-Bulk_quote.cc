#include <iostream>
#include <string>

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
             double disc)  // reference ?
      : Disc_quote(book, price, qty, disc) {}
  double net_price(std::size_t) const override;
};

double Bulk_quote::net_price(std::size_t n) const {
  if (n > quantity_)
    return (1 - discount_) * n * price_;
  else
    return n * price_;
}

int main(int argc, char** argv) {
  Bulk_quote bulk_quote("bbbbb", 10.0, 5, 0.1);

  std::cout << bulk_quote.net_price(20) << std::endl;
}
