#include <iostream>
#include "include/Sales_item.h"

int main(){
  Sales_item current_item, item;
  if (std::cin >> current_item){
    int counter = 1;
    while(std::cin >> item){
      if(current_item.isbn() == item.isbn())
        counter ++;
      else{
        std::cout << current_item.isbn() << " has " << counter << "items" << std::endl;
        current_item = item;
	counter = 1;
      }
    }
  std::cout << current_item.isbn() << " has " << counter << "items " << std::endl;
  }
  return 0;
}
