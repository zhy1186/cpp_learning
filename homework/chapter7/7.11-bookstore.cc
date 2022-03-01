#include "include/Sales_data.h"

int main(int argc, char** argv) {
  Sales_data sales_data_default;
  print(std::cout, sales_data_default);

  Sales_data sales_data_isbn("test_isbn");
  print(std::cout, sales_data_isbn);

  Sales_data sales_data_all("test_isbn", 3, 8.2);
  print(std::cout, sales_data_all);

  Sales_data sales_data_read(std::cin);
  print(std::cout, sales_data_read);

  return 0;
}
