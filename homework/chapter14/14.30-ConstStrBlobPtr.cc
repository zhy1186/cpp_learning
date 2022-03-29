#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;

 public:
  typedef vector<string>::size_type size_type;

  // constructors
  StrBlob() : data(make_shared<vector<string>>()) {}
  StrBlob(initializer_list<string> il);

  // size operations
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  // add and remove elements
  void push_back(const string& t) { data->push_back(t); }
  void pop_back();

  // element access
  string& front();
  string& back();
  string& front() const;
  string& back() const;
  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr cbegin() const;
  ConstStrBlobPtr cend() const;

 private:
  shared_ptr<vector<string>> data;
  // throws msg if data[i] isn't valid
  void check(size_type i, const string& msg) const;
};

StrBlob::StrBlob(initializer_list<string> il)
    : data(make_shared<vector<string>>(il)) {}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

void StrBlob::check(size_type i, const string& msg) const {
  if (i >= data->size()) throw out_of_range(msg);
}

string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

string& StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}
string& StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

string& StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

class StrBlobPtr {
 public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  string& operator*() const;
  string* operator->() const;
  string& deref() const;
  StrBlobPtr& incr();

 private:
  weak_ptr<vector<string>> wptr;
  size_t curr;
  shared_ptr<vector<string>> check(size_t index, const string& msg) const;
};

inline StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
inline StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
string& StrBlobPtr::deref() const {
  auto p = check(curr, "out of range");
  return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  curr++;
  return *this;
}

string& StrBlobPtr::operator*() const {
  auto p = check(curr, "deref past end.");
  return (*p)[curr];
}

string* StrBlobPtr::operator->() const { return &this->operator*(); }

shared_ptr<vector<string>> StrBlobPtr::check(size_t index,
                                             const string& msg) const {
  auto p = wptr.lock();
  if (!p)
    throw runtime_error("unbound StrBlobPtr");
  else if (curr >= p->size())
    throw runtime_error(msg);
  else
    return p;
}

class ConstStrBlobPtr {
 public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}

  const string& operator*() const;
  const string* operator->() const;

  string& deref() const;
  ConstStrBlobPtr& incr();

 private:
  weak_ptr<vector<string>> wptr;
  size_t curr;
  shared_ptr<vector<string>> check(size_t index, const string& msg) const;
};

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t index,
                                                  const string& msg) const {
  auto p = wptr.lock();
  if (!p)
    throw runtime_error("unbound StrBlobPtr");
  else if (curr >= p->size())
    throw runtime_error(msg);
  else
    return p;
}

const string& ConstStrBlobPtr::operator*() const {
  auto p = check(curr, "deref past end.");
  return (*p)[curr];
}

const string* ConstStrBlobPtr::operator->() const { return &this->operator*(); }

ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::cend() const {
  return ConstStrBlobPtr(*this, data->size());
}
string& ConstStrBlobPtr::deref() const {
  auto p = check(curr, "out of range");
  return (*p)[curr];
}