#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult;
class TextQuery {
  friend class QueryResult;

 public:
  TextQuery() = default;
  TextQuery(std::string& path) : lines(new std::vector<std::string>) {
    std::ifstream ifs(path);
    std::string line{};
    int line_number = 0;
    while (std::getline(ifs, line)) {
      lines->push_back(line);
      ++line_number;
      std::istringstream iss(line);
      std::string word{};
      while (iss >> word) {
        auto& word_line_nums = word_info[word];
        if (!word_line_nums) word_line_nums.reset(new std::set<int>);
        word_line_nums->insert(line_number);
      }
    }
  }

  QueryResult query(const std::string) const;

 private:
  std::shared_ptr<std::vector<std::string>> lines{};
  std::map<std::string, std::shared_ptr<std::set<int>>> word_info{};
};

class QueryResult {
  friend std::ostream& print(std::ostream&, const QueryResult&);

 public:
  QueryResult() = default;
  QueryResult(const std::string s, std::shared_ptr<std::set<int>> p_lines_num,
              std::shared_ptr<std::vector<std::string>> p_lines)
      : target(s), lines_num(p_lines_num), lines(p_lines) {}

 private:
  std::string target{};
  std::shared_ptr<std::set<int>> lines_num{};
  std::shared_ptr<std::vector<std::string>> lines{};
};

std::ostream& print(std::ostream& os, const QueryResult& qr) {
  os << qr.target << " occurs " << qr.lines_num->size() << " time(s) "
     << std::endl;
  for (auto i : *qr.lines_num) {
    os << "[line" << i + 1 << "] " << *(qr.lines->begin() + i - 1) << std::endl;
  }
  return os;
};

QueryResult TextQuery::query(const std::string target) const {
  static std::shared_ptr<std::set<int>> nodata(new std::set<int>);
  auto location = word_info.find(target);
  if (location == word_info.end())
    return QueryResult(target, nodata, lines);
  else
    return QueryResult(target, location->second, lines);
}

int main(int argc, char** argv) {
  std::string path =
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter12/include/test.txt";
  TextQuery tq(path);
  while (true) {
    std::cout << "Input a word to look up, q to quit:" << std::endl;
    std::string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, tq.query(s)) << std::endl;
  }
  return 0;
}
