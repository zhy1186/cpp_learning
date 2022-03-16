#include <deque>
#include <iostream>
#include <list>

int main(int argc, char** argv) {
  std::list<int> test{1, 4, 5, 2, 6, 7, 2, 636, 75, 35, 2};
  std::deque<int> odd{};
  std::deque<int> even{};

  for (auto itr = test.cbegin(); itr != test.cend(); ++itr) {
    if ((*itr % 2) == 1)
      odd.push_back(*itr);
    else
      even.push_back(*itr);
  }

  return 0;
}
