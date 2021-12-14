#include <iostream>

using std::cout, std::cin, std::endl;

int main(){
  cout << "Input two int numbers:\n";
  int a, b;
  cin >> a >> b;
  
  int begin, end;
  begin = a > b ? b : a;
  end = a > b ? a : b;

  while(begin <= end){
    cout << begin << endl;
    ++begin;
  }  
  return 0;
}
