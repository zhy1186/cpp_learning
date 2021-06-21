#include <iostream>
#include "include/Sales_item.h"
int main(){
  Sales_item item, item_sumup;
  while(std::cin >> item){
    item_sumup += item;
  }
  std::cout << "Sum is " << item_sumup << std::endl;
  return 0;
}
