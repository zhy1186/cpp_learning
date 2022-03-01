#include "Sales_data.h"

#include <fstream>

int main(int argc, char* argv[]) {
  std::ifstream ifs(argv[1]);
  std::ofstream ofs(argv[2], ofstream::app);
  if (!ifs.good()) {
  	std::cerr << "File Open Failed!" << std::endl;
  	return -1;
  }

  Sales_data total;
  if (read(ifs, total)) {
    Sales_data trans;
    while(read(ifs ,trans)) {
      if(total.isbn() == trans.isbn())
        total.combine(trans);
      else {
        print(ofs, total) << std::endl;
        total = trans;
      }
    }
    print(ofs, total) << std::endl;
  } else {
    std::cerr << " No data." << std::endl;
  }
  return 0;
}
