#include "include/StrBlob.h"

class StrBlobPtr {
 public:
  StrBlobPtr() : curr(0){};
  StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz){};
  std::string &deref() const;
  StrBlobPtr &incr();

 private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(
    std::size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret) throw std::runtime_error("unbound StrBlobPtr");
  if (i >= ret->size()) throw std::out_of_range(msg);
  return ret;
}

std::string &StrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
  check(curr, "Increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() {
  auto ret = StrBlobPtr(*this, data->size());
  return ret;
}

int main(int argc, char **argv) {
  StrBlob str_blob({"aaa", "bbb", "ccc"});
  StrBlobPtr str_blob_ptr(str_blob);
}
