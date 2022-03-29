#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class StrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;

 public:
  using size_type = std::vector<std::string>::size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> lst);

  std::string& operator[](std::size_t n);
  const std::string& operator[](std::size_t n) const;

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const std::string& t) { data->push_back(t); }
  void push_back(std::string&& t) { data->push_back(std::move(t)); }
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

void StrBlob::check(size_type i, const std::string& msg) const {
  if (i >= data->size()) throw std::out_of_range(msg);
}

std::string& StrBlob::operator[](std::size_t n) { return (*data)[n]; }

const std::string& StrBlob::operator[](std::size_t n) const {
  return (*data)[n];
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

class StrBlobPtr {
 public:
  StrBlobPtr() : curr(0){};
  StrBlobPtr(const StrBlob& a, std::size_t sz = 0) : wptr(a.data), curr(sz){};

  std::string& operator[](std::size_t n);
  const std::string& operator[](std::size_t n) const;
  StrBlobPtr operator++(int);
  StrBlobPtr operator--(int);
  StrBlobPtr& operator++();
  StrBlobPtr& operator--();
  StrBlobPtr& operator+=(std::size_t n);
  StrBlobPtr& operator-=(std::size_t n);
  StrBlobPtr operator+(std::size_t n);
  StrBlobPtr operator-(std::size_t n);

  std::string& deref() const;
  StrBlobPtr& incr();

 private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string&) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(
    std::size_t i, const std::string& msg) const {
  auto ret = wptr.lock();
  if (!ret) throw std::runtime_error("unbound StrBlobPtr");
  if (i >= ret->size()) throw std::out_of_range(msg);
  return ret;
}

std::string& StrBlobPtr::operator[](std::size_t n) { return (*wptr.lock())[n]; }

const std::string& StrBlobPtr::operator[](std::size_t n) const {
  return (*wptr.lock())[n];
}

StrBlobPtr& StrBlobPtr::operator++() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
  auto ret = *this;
  ++*this;
  return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
  auto ret = *this;
  --*this;
  return ret;
}

StrBlobPtr& StrBlobPtr::operator--() {
  --curr;
  check(curr, "increment past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr& StrBlobPtr::operator+=(std::size_t n) {
  curr += n;
  check(curr, "increment past end of StrBlobPtr");
  return *this;
}

StrBlobPtr& StrBlobPtr::operator-=(std::size_t n) {
  curr -= n;
  check(curr, "increment past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator+(std::size_t n) { return (*this) += n; }

StrBlobPtr StrBlobPtr::operator-(std::size_t n) { return (*this) -= n; }

std::string& StrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
  check(curr, "Increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() {
  auto ret = StrBlobPtr(*this, data->size());
  return ret;
}