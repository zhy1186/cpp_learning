#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
class BlobPtr;

template <typename T>
class Blob;

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob {
  friend class BlobPtr<T>;

  friend bool operator==<T>(const Blob<T>&, const Blob<T>&);

 public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;

  Blob();
  Blob(std::initializer_list<T> il);
  template <typename Iter>
  Blob(Iter, Iter);

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  void push_back(const T& t) { data->push_back(t); }
  void push_back(T&& t) { data->push_back(std::move(t)); }

  void pop_back();

  T& back();
  T& front();
  T& back() const;
  T& front() const;

  T& operator[](size_type i);

 private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string& msg) const;
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il)
    : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
template <typename Iter>
Blob<T>::Blob(Iter beg, Iter end)
    : data(std::make_shared<std::vector<T>>(beg, end)) {}

template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const {
  if (i >= data.size()) throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back() {
  check(0, "back on empty blob");
  return data->back();
}

template <typename T>
T& Blob<T>::front() {
  check(0, "front on empty blob");
  return data->front();
}

template <typename T>
T& Blob<T>::back() const {
  check(0, "back on empty blob");
  return data->back();
}

template <typename T>
T& Blob<T>::front() const {
  check(0, "front on empty blob");
  return data->front();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
  check(i, "subscript out of range");
  return *(data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
  check(0, "pop back on empty blob");
  data->pop_back();
}

template <typename T>
class BlobPtr {
 public:
  BlobPtr() : curr(0) {}
  BlobPtr(Blob<T>& a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
  T& operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }
  BlobPtr& operator++();
  BlobPtr operator++(int);
  BlobPtr& operator--();
  BlobPtr operator--(int);

 private:
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
  std::weak_ptr<std::vector<T>> wptr;
  std::size_t curr;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
  BlobPtr ret = *this;
  ++*this;
  return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
  check(++curr, "++ pass end");
  return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
  BlobPtr ret = *this;
  --*this;
  return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
  check(--curr, "-- pass 0");
  return *this;
}

int main() {
  std::vector<std::string> str_vec = {"aaa", "bbb", "ccc", "ddd"};
  Blob<std::string> blob(str_vec.begin(), str_vec.end());
  BlobPtr<std::string> blob_ptr(blob);

  return 0;
}
