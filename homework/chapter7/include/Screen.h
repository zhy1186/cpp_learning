#include <string>
#include <iostream>
#include <vector>

class Screen;

class Window_mgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;

  void clear(ScreenIndex);

private:
  std::vector<Screen> screens;
};

class Screen{
public:
  using pos = std::string::size_type;

  Screen() = default;
  Screen(pos ht, pos wt) : height(ht), width(wt), contents(ht * wt, ' ') {}
  Screen(pos ht, pos wt, char c) : height(ht), width(wt), contents(ht * wt, c) {}
  char get() const {return contents[cursor];}
  inline char get(pos r, pos c) const;
  inline Screen& move(pos r, pos c);
  inline Screen& set(char c);
  inline Screen& set(pos r, pos col, char ch);
  Screen& display(std::ostream &os) {
    do_display(os);
    return *this;
  }
  const Screen& display(std::ostream &os) const {
    do_display(os);
    return *this;
  }

  void some_member() const;

  friend void Window_mgr::clear(ScreenIndex);
private:
  void do_display(std::ostream& os) const {os << contents;}

  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  mutable size_t access_ctr;
};

char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

Screen& Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

void Screen::some_member() const {
  ++ access_ctr;
}

Screen& Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

Screen& Screen::set(pos r, pos col, char ch) {
  contents[r * width + col] = ch;
  return *this;
}

void Window_mgr::clear(ScreenIndex i) {
  Screen& s = screens[i];
  s.contents = std::string(s.height * s.height, ' ');
}
