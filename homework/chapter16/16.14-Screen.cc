#include <iostream>
#include <string>
#include <vector>

template <unsigned H, unsigned W>
class Screen;
template <unsigned H, unsigned W>
std::ostream& operator<<(std::ostream& os, const Screen<H, W>&);
template <unsigned H, unsigned W>
std::istream& operator>>(std::istream& is, Screen<H, W>&);

template <unsigned H, unsigned W>
class Screen {
 public:
  using pos = std::string::size_type;

  Screen() = default;
  Screen(pos ht, pos wt) : height(ht), width(wt), contents(ht * wt, ' ') {}
  Screen(pos ht, pos wt, char c) : height(ht), width(wt), contents(H * W, c) {}
  char get() const { return contents[cursor]; }
  inline char get(pos r, pos c) const;
  inline Screen& move(pos r, pos c);
  inline Screen& set(char c);
  inline Screen& set(pos r, pos col, char ch);

  void some_member() const;

  friend std::ostream& operator<<<H, W>(std::ostream& os,
                                        const Screen<H, W>& c);
  friend std::istream& operator>>
      <H, W>(std::istream& is, const Screen<H, W>& c);

 private:
  pos cursor = 0;
  pos height = H, width = W;
  std::string contents;
  mutable size_t access_ctr;
};

template <unsigned H, unsigned W>
char Screen<H, W>::get(pos r, pos c) const {
  pos row = r * W;
  return contents[row + c];
}

template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::move(pos r, pos c) {
  pos row = r * W;
  cursor = row + c;
  return *this;
}

template <unsigned H, unsigned W>
void Screen<H, W>::some_member() const {
  ++access_ctr;
}

template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::set(char c) {
  contents[cursor] = c;
  return *this;
}

template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::set(pos r, pos col, char ch) {
  contents[r * W + col] = ch;
  return *this;
}

template <unsigned H, unsigned W>
std::ostream& operator<<(std::ostream& os, const Screen<H, W>& c) {
  for (int i = 0; i < c.height; i++) os << c.contents.substr(i * W, W);
  return os;
}

template <unsigned H, unsigned W>
std::istream& operator>>(std::istream& is, const Screen<H, W>& c) {
  char a;
  is >> a;
  std::string tmp(H * W, a);
  c.contents = tmp;
  return is;
}
