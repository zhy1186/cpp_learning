#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult;
class TextQuery {
  using line_no = std::vector<std::string>::size_type;

 public:
  TextQuery(std::ifstream&);
  QueryResult query(const std::string&) const;

 private:
  std::shared_ptr<std::vector<std::string>> file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream& is) : file(new std::vector<std::string>) {
  std::string text;
  while (std::getline(is, text)) {
    file->push_back(text);
    int n = file->size() - 1;
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
  QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
              std::shared_ptr<std::vector<std::string>> f)
      : sought(s), lines(p), file(f) {}

  std::set<line_no>::iterator begin() { return lines->begin(); }
  std::set<line_no>::iterator end() { return lines->end(); }
  std::shared_ptr<std::vector<std::string>> get_file() { return file; }

 private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;
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
    os << "\t(line" << num + 1 << " )" << *(qr.file->begin() + num)
       << std::endl;
  }
  return os;
}

class Query_base {
  friend class Query;

 protected:
  using line_no = std::vector<std::string>::size_type;
  virtual ~Query_base() = default;

 private:
  virtual QueryResult eval(const TextQuery&) const = 0;
  virtual std::string rep() const = 0;
};

class Query {
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);

 public:
  Query(const std::string&);
  QueryResult eval(const TextQuery& t) const { return q->eval(t); }
  std::string rep() const { return q->rep(); }

 private:
  Query(std::shared_ptr<Query_base> query) : q(query) {
    std::cout << "call Query(std::string&)" << std::endl;
  }
  std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream& os, const Query& query) {
  return os << query.rep();
}

class WordQuery : public Query_base {
  friend class Query;
  WordQuery(const std::string& s) : query_word(s) {
    std::cout << "call WordQuery(const std::string& s)" << std::endl;
  }
  QueryResult eval(const TextQuery& t) const { return t.query(query_word); }
  std::string rep() const { return query_word; }
  std::string query_word;
};

inline Query::Query(const std::string& s) : q(new WordQuery(s)) {
  std::cout << "call Query(const std::string& s) " << std::endl;
}

class NotQuery : public Query_base {
  friend Query operator~(const Query&);
  NotQuery(const Query& q) : query(q) {
    std::cout << "call NotQuery(const Query& q)" << std::endl;
  }
  std::string rep() const { return "~(" + query.rep() + ")"; }
  QueryResult eval(const TextQuery&) const;
  Query query;
};

QueryResult NotQuery::eval(const TextQuery& text) const {
  auto result = query.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>();

  auto beg = result.begin(), end = result.end();
  auto sz = result.get_file()->size();

  for (size_t n = 0; n != sz; ++n) {
    if (beg == end || *beg != n)
      ret_lines->insert(n);
    else if (beg != end)
      ++beg;
  }
  return QueryResult(rep(), ret_lines, result.get_file());
}

inline Query operator~(const Query& operand) {
  return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
 protected:
  BinaryQuery(const Query& l, const Query& r, std::string s)
      : lhs(l), rhs(r), opSym(s) {
    std::cout
        << "call BinaryQuery(const Query& l, const Query& r, std::string s)"
        << std::endl;
  }
  std::string rep() const {
    return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
  }
  Query lhs, rhs;
  std::string opSym;
};

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query&, const Query&);
  AndQuery(const Query& left, const Query& right)
      : BinaryQuery(left, right, "&") {
    std::cout << "call AndQuery(const Query& left, const Query& right)"
              << std::endl;
  }
  QueryResult eval(const TextQuery&) const;
};

QueryResult AndQuery::eval(const TextQuery& text) const {
  auto left = lhs.eval(text);
  auto right = rhs.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>();

  std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                        std::inserter(*ret_lines, ret_lines->begin()));
  return QueryResult(rep(), ret_lines, left.get_file());
}

inline Query operator&(const Query& lhs, const Query& rhs) {
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query&, const Query&);
  OrQuery(const Query& left, const Query& right)
      : BinaryQuery(left, right, "|") {
    std::cout << "call OrQuery(const Query& left, const Query& right)"
              << std::endl;
  }
  QueryResult eval(const TextQuery&) const;
};

QueryResult OrQuery::eval(const TextQuery& text) const {
  auto right = rhs.eval(text), left = lhs.eval(text);
  auto ret_lines =
      std::make_shared<std::set<line_no>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return QueryResult(rep(), ret_lines, left.get_file());
}

inline Query operator|(const Query& lhs, const Query& rhs) {
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

int main(int argc, char** argv) {
  std::ifstream infile;
  infile.open(
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter15/include/"
      "story.txt");
  TextQuery file = infile;

  Query q = Query("fiery") & Query("bird") | Query("wind");
  const auto results = q.eval(file);
  std::cout << "\nExecuting Query for: " << q << std::endl;
  print(std::cout, results) << std::endl;
  infile.close();
}
