#include <iostream>
#include <string>
#include <utility>

class Quote {
 public:
  Quote() { std::cout << "call Quote::Quote()" << std::endl; };
  Quote(const std::string& book, double sales_price)
      : book_no_(book), price_(sales_price) {
    std::cout << "call Quote(const std::string& book, double sales_price)"
              << std::endl;
  }
  Quote(const Quote& rhs) : book_no_(rhs.book_no_), price_(rhs.price_) {
    std::cout << "call Quote(const Quote& rhs)" << std::endl;
  }
  Quote& operator=(const Quote& rhs) {
    price_ = rhs.price_;
    book_no_ = rhs.book_no_;
    std::cout << "call Quote& operator=(const Quote& rhs)" << std::endl;
    return *this;
  }

  Quote(Quote&& rhs) noexcept
      : book_no_(std::move(rhs.book_no_)), price_(std::move(rhs.price_)) {
    std::cout << "call Quote(Quote&& rhs) noexcept" << std::endl;
  }
  Quote& operator=(Quote&& rhs) noexcept {
    std::cout << "call Quote& operator=(Quote&& rhs) noexcept" << std::endl;
    book_no_ = std::move(rhs.book_no_);
    price_ = std::move(rhs.price_);
    return *this;
  }

  std::string isbn() const { return book_no_; }
  void debug() const {
    std::cout << "book_no_:" << book_no_ << "\tprice_:" << price_ << std::endl;
  }

  virtual double net_price(std::size_t n) const { return n * price_; }
  virtual ~Quote() { std::cout << "call ~Quote()" << std::endl; };

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

class Bulk_quote : public Quote {
 public:
  Bulk_quote() { std::cout << "call Bulk_quote()" << std::endl; };
  Bulk_quote(const std::string& book, double price, std::size_t qty,
             double disc)
      : Quote(book, price) {
    std::cout << "Bulk_quote(const std::string& book, double price, "
                 "std::size_t qty, double disc)"
              << std::endl;
  }

  Bulk_quote(const Bulk_quote& rhs)
      : Quote(rhs), discount_(rhs.discount_), quantity_(rhs.quantity_) {
    std::cout << "call Bulk_quote(const Bulk_quote& rhs)" << std::endl;
  }

  Bulk_quote& operator=(const Bulk_quote& rhs) {
    Quote::operator=(rhs);
    discount_ = rhs.discount_;
    quantity_ = rhs.quantity_;
    std::cout << "call Bulk_quote& operator=(const Bulk_quote& rhs)"
              << std::endl;
    return *this;
  }

  Bulk_quote(Bulk_quote&& rhs) noexcept
      : Quote(rhs),
        discount_(std::move(rhs.discount_)),
        quantity_(std::move(rhs.quantity_)) {
    std::cout << "call Bulk_quote(Bulk_quote&& rhs)" << std::endl;
  }

  Bulk_quote& operator=(Bulk_quote&& rhs) noexcept {
    Quote::operator=(rhs);
    discount_ = rhs.discount_;
    quantity_ = rhs.quantity_;
    std::cout << "call Bulk_quote& operator=(Bulk_quote&& rhs) noexcept"
              << std::endl;
    return *this;
  }

  ~Bulk_quote() { std::cout << "call ~Bulk_quote()" << std::endl; }

  double net_price(std::size_t) const override;

 private:
  double discount_;
  std::size_t quantity_;
};

double Bulk_quote::net_price(std::size_t n) const {
  if (n > quantity_)
    return (1 - discount_) * n * price_;
  else
    return n * price_;
}

int main(int argc, char** argv) {
  Quote quote("nnnnn", 10.0);
  Bulk_quote bulk_quote("bbbbb", 10.0, 5, 0.1);

  std::cout << quote.net_price(20) << std::endl;
  std::cout << bulk_quote.net_price(20) << std::endl;
}
