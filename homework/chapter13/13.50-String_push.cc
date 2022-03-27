#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class String {
 public:
  String() : String("") {}
  String(const char* s);
  String(const String& s);
  String(String&& s);
  String& operator=(String&& s) noexcept;
  String& operator=(String& s);
  ~String();

  void free();
  size_t size() { return end - begin; }
  std::pair<char*, char*> alloc_n_copy(const char* beg, const char* end);

 private:
  char* begin;
  char* end;
  std::allocator<char> alloc;
};

std::pair<char*, char*> String::alloc_n_copy(const char* beg, const char* end) {
  auto str = alloc.allocate(end - beg);
  return {str, std::uninitialized_copy(beg, end, str)};
}

String::String(const char* s) {
  auto e = s;
  while (*e != '\0') e++;
  e++;  // end position + 1
  auto data = alloc_n_copy(s, e);
  begin = data.first;
  end = data.second;
}

String::String(const String& s) {
  auto data = alloc_n_copy(s.begin, s.end);
  begin = data.first;
  end = data.second;
  std::cout << "String::String(const String& s)" << std::endl;
}

String::String(String&& s) {
  auto new_data = alloc.allocate(s.size());
  auto last =
      std::uninitialized_copy(std::move(s.begin), std::move(s.end), new_data);
  begin = new_data;
  end = last;
  s.begin = s.end = nullptr;
}

String& String::operator=(String& s) {
  auto data = alloc_n_copy(s.begin, s.end);
  free();
  begin = data.first;
  end = data.second;
  std::cout << "String& String::operator=(String& s)" << std::endl;
  return *this;
}

String& String::operator=(String&& s) noexcept {
  if (this != &s) {
    free();
    begin = s.begin;
    end = s.end;
    s.begin = s.end = nullptr;
  }
  std::cout << "String& String::operator=(String&& s)" << std::endl;
  return *this;
}

String::~String() { free(); }

void String::free() {
  if (begin) {
    std::for_each(begin, end, [this](char& c) { alloc.destroy(&c); });
    alloc.deallocate(begin, end - begin);
  }
}

int main() {
  std::vector<String> vec{};
  vec.push_back(String("aaa"));
  vec.push_back(String("bbb"));
  vec.push_back(String("ccc"));

  return 0;
}
