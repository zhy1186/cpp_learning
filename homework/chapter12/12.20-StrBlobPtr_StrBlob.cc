#include <fstream>
#include <iostream>

#include "include/StrBlobPtr.h"

int main(int arc, char** argv) {
  std::string path =
      "/Users/hengyi/Desktop/cpp_learning/homework/chapter12/include/"
      "string.txt";
  std::ifstream ifs(path);
  std::string line;
  StrBlob str_blob;
  while (std::getline(ifs, line)) {
    str_blob.push_back(line);
  }

  StrBlobPtr str_blob_ptr = str_blob.begin();
  int size = str_blob.size();
  while (size--) {
    std::cout << str_blob_ptr.deref() << " ";
    str_blob_ptr.incr();
  }
  return 0;
}
