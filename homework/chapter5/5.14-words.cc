#include <iostream>
#include <string>

int main(){
  std::string inp{};
  std::string last_inp{};
  std::string max_inp{};
  int cnt, max_cnt;

  while (std::cin >> inp){
    if(last_inp.empty()){
      last_inp = inp;
      ++ cnt; 
    }
    else{
      if (inp == last_inp){
        ++ cnt;
        if (cnt >= max_cnt){
        max_cnt = cnt;
        max_inp = last_inp;
        }
      }
      else {
        last_inp = inp;
        cnt = 1;
      }
    }
  }
  std::cout << "max_inp: " << max_inp << " number: " << max_cnt << std::endl;
  return 0;
}
