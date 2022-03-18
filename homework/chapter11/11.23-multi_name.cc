#include <iostream>
#include <map>

using namespace std;

int main() {
  multimap<string, string> family;
  family.insert({"jackson", "michael"});
  family.insert({"jackson", "david"});
  family.insert({"wang", "shi"});
  for (auto x : family)
    cout << "family " << x.first << " has " << x.second << endl;
  return 0;
}