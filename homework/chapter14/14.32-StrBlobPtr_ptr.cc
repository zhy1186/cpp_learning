#include "include/StrBlob.h"

class StrBlobPtrPtr {
 public:
  StrBlobPtrPtr() = default;
  StrBlobPtrPtr(StrBlobPtr* p) : ptr(p) {}

  StrBlobPtr& operator*() const;
  StrBlobPtr* operator->() const;

 private:
  StrBlobPtr* ptr = nullptr;
};

StrBlobPtr& StrBlobPtrPtr::operator*() const { return *ptr; }

StrBlobPtr* StrBlobPtrPtr::operator->() const { return &this->operator*(); }
