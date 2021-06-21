#include <iostream>
int main(){
  int current_value = 0, val = 0;
  if (std::cin >> current_value){
    int counter = 1;
    while (std::cin >> val){
      if (val == current_value){
        ++ counter;
        }
      else{
        std::cout << current_value << " occurs " << counter <<
        " times "<< std::endl;
        current_value = val;
        counter = 1;
        }
      }
      std::cout << current_value << " occurs " << counter << " times " << std::endl;

    }
  return 0;
}
