#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "include/StrBlob.h"

class QueryResult;
class TextQuery {
  using line_no = std::vector<std::string>::size_type;

 public:
  TextQuery(std::ifstream&);
  QueryResult query(const std::string&) const;

 private:
  StrBlob file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream& is) {
  std::string text;
  while (std::getline(is, text)) {
    file.push_back(text);
    int n = file.size() - 1;
    std::istringstream line(text);
    std::string word;
    while (line >> word) {
      auto& lines = wm[word];
      if (!lines) lines.reset(new std::set<line_no>);
      lines->insert(n);
    }
  }
}

class QueryResult {
  using line_no = std::vector<std::string>::size_type;
  friend std::ostream& print(std::ostream&, const QueryResult&);

 public:
  QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, StrBlob f)
      : sought(s), lines(p), file(f) {}

 private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  StrBlob file;
};

QueryResult TextQuery::query(const std::string& sought) const {
  static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

  auto loc = wm.find(sought);
  if (loc == wm.end())
    return QueryResult(sought, nodata, file);
  else
    return QueryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " times." << std::endl;
  for (auto num : *qr.lines) {
    const auto qr_result = StrBlobPtr(qr.file, num);
    os << "\t(line" << num + 1 << " )" << (qr_result.deref()) << std::endl;
  }
  return os;
}

int main() {
  std::string file =
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter12/include/test.txt";
  std::ifstream ifs(file);
  TextQuery tq(ifs);
  while (true) {
    std::cout << "Enter a word to look up, for q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, tq.query(s)) << std::endl;
  }
}
