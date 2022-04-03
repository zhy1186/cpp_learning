#include <algorithm>  //equal_range
#include <fstream>
#include <iostream>
#include <numeric>  //accumulate
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "include/Sales_data.h"

typedef std::tuple<std::vector<Sales_data>::size_type,
                   std::vector<Sales_data>::const_iterator,
                   std::vector<Sales_data>::const_iterator>
    matches;
typedef std::pair<std::vector<Sales_data>::size_type,
                  std::pair<std::vector<Sales_data>::const_iterator,
                            std::vector<Sales_data>::const_iterator>>
    matches_pair;
inline bool compareIsbn(const Sales_data &ls, const Sales_data &rs) {
  return ls.isbn() < rs.isbn();
}

std::vector<matches> findbook(const std::vector<std::vector<Sales_data>> &f,
                              const std::string &book)  // 17.4
{
  std::vector<matches> ret;
  for (auto it = f.cbegin(); it != f.cend(); ++it) {
    auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
    if (found.first != found.second)
      ret.push_back(make_tuple(it - f.cbegin(), found.first, found.second));
  }
  return ret;
}
std::vector<matches_pair> findbook_pair(
    const std::vector<std::vector<Sales_data>> &f,
    const std::string &book)  // 17.5
{
  std::vector<matches_pair> ret;
  for (auto it = f.cbegin(); it != f.cend(); ++it) {
    auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
    if (found.first != found.second)
      ret.push_back(
          make_pair(it - f.cbegin(), make_pair(found.first, found.second)));
  }
  return ret;
}
struct matches_struct  // 17.6
{
  std::vector<Sales_data>::size_type st;
  std::vector<Sales_data>::const_iterator first;
  std::vector<Sales_data>::const_iterator second;
  matches_struct(std::vector<Sales_data>::size_type s,
                 std::vector<Sales_data>::const_iterator fi,
                 std::vector<Sales_data>::const_iterator se)
      : st(s), first(fi), second(se) {}
};
std::vector<matches_struct> findbook_struct(
    const std::vector<std::vector<Sales_data>> &f, const std::string &book) {
  std::vector<matches_struct> ret;
  for (auto it = f.cbegin(); it != f.cend(); ++it) {
    auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
    if (found.first != found.second)
      ret.push_back(matches_struct(it - f.cbegin(), found.first, found.second));
  }
  return ret;
}
void reportRestults(std::istream &is, std::ostream &os,
                    const std::vector<std::vector<Sales_data>> &f) {
  std::string s;
  while (is >> s) {
    auto tran = findbook(f, s);
    if (tran.empty()) {
      std::cout << s << " not found in any stores" << std::endl;
      continue;
    }
    for (const auto &x : tran)
      os << "store " << std::get<0>(x) << " sales: "
         << std::accumulate(std::get<1>(x), std::get<2>(x), Sales_data(s))
         << std::endl;
  }
}
std::vector<Sales_data> *write_sales(std::fstream &f) {
  Sales_data temp;
  auto ptr = new std::vector<Sales_data>;
  while (read(f, temp)) {
    ptr->push_back(temp);
  }
  return ptr;
}
int main(int argc, char **argv) {
  using namespace std;
  fstream f1(argv[1]), f2(argv[2]), f3(argv[3]);
  if (!f1 && !f2 && !f3) {
    cerr << "error!";
    exit(1);
  }
  std::vector<std::vector<Sales_data>> file;
  file.push_back(*write_sales(f1));
  file.push_back(*write_sales(f2));
  file.push_back(*write_sales(f3));

  reportRestults(cin, cout, file);
  system("pause");
  return 0;
}