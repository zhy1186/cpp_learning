#include <iostream>
#include "include/Sales_data.h"

int main() {
  Sales_data total;
  total.bookNo = "abcdefg";
  total.units_sold = 1;
  total.revenue = 16.8;

  Sales_data trans;
  trans.bookNo = "abcdefg";
  trans.units_sold = 2;
  trans.revenue = 33.6;
 
  if(total.bookNo == trans.bookNo){
    total.units_sold += trans.units_sold;
    total.revenue += trans.revenue;
  }

  std::cout << total.bookNo << '\t' << total.units_sold << '\t' << total.revenue << std::endl;
  
  if(trans.bookNo.empty()){
    std::cerr << "No data !" << std::endl;
    return -1;
  }
  return 0;
}
