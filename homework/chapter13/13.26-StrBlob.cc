#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlob {
  friend class StrBlobPtr;

 public:
  using size_type = std::vector<std::string>::size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> lst);
  StrBlob(const StrBlob&);
  StrBlob& operator=(const StrBlob&);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const std::string& t) { data->push_back(t); }
  void pop_back();
  std::string& front();
  std::string& front() const;
  std::string& back();
  std::string& back() const;
  StrBlobPtr begin();
  StrBlobPtr end();

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string& msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> lst)
    : data(std::make_shared<std::vector<std::string>>(lst)) {}

StrBlob::StrBlob(const StrBlob& rhs) {
  data = std::make_shared<std::vector<std::string>>(*rhs.data);
}

StrBlob& operator=(const StrBlob& rhs) {
  data = std::make_shared<std::vector<std::string>>(*rhs.data);
  return *this;
}

void StrBlob::check(size_type i, const std::string& msg) const {
  if (i >= data->size()) throw std::out_of_range(msg);
}

std::string& StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

std::string& StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}