#include <iostream>
#include <string>

inline unsigned MonthStringToNumber(std::string mon) {
  if (mon == "January" || mon == "Jan") return 1;
  if (mon == "February" || mon == "Fen") return 2;
  if (mon == "March" || mon == "Mar") return 3;
  if (mon == "April" || mon == "Apr") return 4;
  if (mon == "May" || mon == "Mar") return 5;
  if (mon == "June" || mon == "Jun") return 6;
  if (mon == "July" || mon == "Jul") return 7;
  if (mon == "August" || mon == "Aug") return 8;
  if (mon == "September" || mon == "Sep") return 9;
  if (mon == "October" || mon == "Oct") return 10;
  if (mon == "November" || mon == "Nov")
    return 11;
  else
    return 12;
}

class Date {
 public:
  Date() = default;
  Date(std::string inp) {
    std::string comma = ",";
    std::string slash = "/";
    std::string letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string::size_type pos1 = 0, pos2 = 0;

    // January 1, 1990
    if ((pos2 = inp.find_first_of(comma)) != std::string::npos) {
      pos1 = inp.find_last_of(letter);
      pos2 = inp.find_first_of(comma);

      month_ = MonthStringToNumber(inp.substr(0, pos1 + 1));
      day_ = stoi(inp.substr(pos1 + 2, 2));
      year_ = stoi(inp.substr(pos2 + 2, 4));
      return;
    }

    // 1/1/1990
    if ((pos1 = inp.find_first_of(slash)) != std::string::npos) {
      pos2 = inp.find_last_of(slash);

      month_ = stoi(inp.substr(0, 1));
      day_ = stoi(inp.substr(pos1 + 1, 1));
      year_ = stoi(inp.substr(pos2 + 1, 4));
      return;
    }

    // Jan 1 1990
    else {
      pos1 = inp.find_first_of(" ");
      pos2 = inp.find_last_of(" ");
      month_ = MonthStringToNumber(inp.substr(0, pos1));
      day_ = stoi(inp.substr(pos1 + 1, 1));
      year_ = stoi(inp.substr(pos2 + 1, 4));
      return;
    }
  }

  inline void show() {
    std::cout << "year: " << year_ << " month: " << month_ << " day: " << day_
              << std::endl;
  }

 private:
  unsigned year_;
  unsigned month_;
  unsigned day_;
};

int main(int argc, char** argv) {
  Date date1("January 1, 1990");
  date1.show();
  Date date2("1/1/1990");
  date2.show();
  Date date3("Jan 1 1990");
  date3.show();

  return 0;
}
