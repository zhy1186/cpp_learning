#pragma once

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class StrVec {
 public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
  StrVec(std::initializer_list<std::string> &);
  ~StrVec();

  void push_back(const std::string &);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  void reserve(size_t n) {
    if (n <= capacity()) return;
    alloc_n_move(n);
  };
  void resize(size_t n, const std::string &s = "");

  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

 private:
  static std::allocator<std::string> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) reallocate();
  }
  void alloc_n_move(size_t);
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();
  void reallocate();

  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

void StrVec::push_back(const std::string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(
    const std::string *b, const std::string *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
};

void StrVec::alloc_n_move(size_t capacity) {
  auto newdata = alloc.allocate(capacity);

  auto dest = newdata;
  auto elem = elements;

  for (size_t i = 0; i != size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  elements = newdata;
  first_free = dest;
  cap = elements + capacity;
};

void StrVec::free() {
  if (elements) {
    for (auto p = first_free; p != elements;) alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}

StrVec::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string> &lst) {
  auto newdata = alloc_n_copy(lst.begin(), lst.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
};

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

void StrVec::reallocate() {
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

void StrVec::resize(size_t n, const std::string &s) {
  if (n > size()) {
    if (n > capacity()) reserve(n);

    for (size_t i = size(); i < n; ++i) {
      alloc.construct(first_free++, s);
    }
  }
  if (n < size()) {
    while ((elements + n) != first_free) {
      alloc.destroy(--first_free);
    }
  }
}