#include <iostream>
#include <list>
#include <vector>

int main(int argc, char** argv) {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::list<int> lst{};
  std::vector<int> vec{};
  for (int i = 0; i < 10; ++i) {
    lst.push_back(ia[i]);
    vec.push_back(ia[i]);
  }
  
  for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
    if ((*itr) % 2) itr = lst.erase(itr);
  }

  for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
    if (*(itr + 1) % 2) itr = vec.erase(itr);
  }

  for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
    std::cout << *itr << std::endl;
  }

  std::cout << "----------" << std::endl;
  for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
    std::cout << *itr << std::endl;
  }
}
