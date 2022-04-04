#include <iostream>
#include <string>

struct out_of_stock : public std::runtime_error {
  explicit out_of_stock(const std::string &s) : std::runtime_error(s) {}
};

struct isbn_mismatch : public std::logic_error {
  explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
  isbn_mismatch(const std::string &s, const std::string &ls,
                const std::string &rs)
      : std::logic_error(s), left(ls), right(rs) {}
  std::string left;
  std::string right;
};