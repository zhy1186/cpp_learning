#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>

class Quote {
 public:
  Quote() { std::cout << "call Quote::Quote()" << std::endl; };
  Quote(const std::string& book, double sales_price)
      : book_no_(book), price_(sales_price) {}
  Quote(const Quote& rhs) : book_no_(rhs.book_no_), price_(rhs.price_) {}
  Quote& operator=(const Quote& rhs) {
    price_ = rhs.price_;
    book_no_ = rhs.book_no_;
    return *this;
  }

  Quote(Quote&& rhs) noexcept
      : book_no_(std::move(rhs.book_no_)), price_(std::move(rhs.price_)) {}
  Quote& operator=(Quote&& rhs) noexcept {
    book_no_ = std::move(rhs.book_no_);
    price_ = std::move(rhs.price_);
    return *this;
  }

  virtual Quote* clone() const& { return new Quote(*this); }
  virtual Quote* clone() const&& { return new Quote(std::move(*this)); }

  std::string isbn() const { return book_no_; }
  void debug() const {
    std::cout << "book_no_:" << book_no_ << "\tprice_:" << price_ << std::endl;
  }

  virtual double net_price(std::size_t n) const {
    std::cout << "call Quote::net_price()" << std::endl;
    return n * price_;
  }
  virtual ~Quote(){};

 protected:
  double price_ = 0.0;

 private:
  std::string book_no_;
};

double print_total(std::ostream& os, const Quote& item, std::size_t n) {
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
      : Quote(book, price), quantity_(qty), discount_(disc) {}

  Bulk_quote(const Bulk_quote& rhs)
      : Quote(rhs), discount_(rhs.discount_), quantity_(rhs.quantity_) {}

  Bulk_quote& operator=(const Bulk_quote& rhs) {
    Quote::operator=(rhs);
    discount_ = rhs.discount_;
    quantity_ = rhs.quantity_;
    return *this;
  }

  Bulk_quote(Bulk_quote&& rhs) noexcept
      : Quote(rhs),
        discount_(std::move(rhs.discount_)),
        quantity_(std::move(rhs.quantity_)) {}

  Bulk_quote& operator=(Bulk_quote&& rhs) noexcept {
    Quote::operator=(rhs);
    discount_ = rhs.discount_;
    quantity_ = rhs.quantity_;
    return *this;
  }

  Bulk_quote* clone() const& override { return new Bulk_quote(*this); }
  Bulk_quote* clone() const&& override {
    return new Bulk_quote(std::move(*this));
  }

  ~Bulk_quote() {}

  double net_price(std::size_t) const override;

 private:
  double discount_;
  std::size_t quantity_;
};

double Bulk_quote::net_price(std::size_t n) const {
  std::cout << "call Bulk_quote::net_price()" << std::endl;
  if (n > quantity_)
    return (1 - discount_) * n * price_;
  else
    return n * price_;
}

class Basket {
 public:
  void add_item(const Quote& sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
  }
  void add_item(Quote&& sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
  }

  double total_receipt(std::ostream&) const;

 private:
  static bool compare(const std::shared_ptr<Quote>& lhs,
                      const std::shared_ptr<Quote>& rhs) {
    return lhs->isbn() < rhs->isbn();
  }
  std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(std::ostream& os) const {
  double sum = 0.0;
  for (auto iter = items.cbegin(); iter != items.cend();
       iter = items.upper_bound(*iter)) {
    sum += print_total(os, **iter, items.count(*iter));
  }
  os << "Total sale: " << sum << std::endl;
  return sum;
}

int main(int argc, char** argv) {
  Basket basket{};
  basket.add_item(Quote("quote", 15.0));
  basket.add_item(Bulk_quote("bulk_quote", 10.0, 3, 0.2));
  basket.add_item(Quote("quote", 15.0));
  basket.add_item(Bulk_quote("bulk_quote", 10.0, 3, 0.2));
  basket.add_item(Bulk_quote("bulk_quote", 10.0, 3, 0.2));
  basket.add_item(Bulk_quote("bulk_quote", 10.0, 3, 0.2));
  basket.add_item(Bulk_quote("bulk_quote", 10.0, 3, 0.2));

  basket.total_receipt(std::cout);
}