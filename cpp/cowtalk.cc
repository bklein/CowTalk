#include "cowtalk.hpp"
#include "cowtalk.h"

namespace cow_talk {

class CowTalk::Impl {
 public:
  Impl()
    : message_("I'm a cow. moo") {}

  std::string talk() const {
    return message_;
  }
  ~Impl() {}
 private:
  const std::string message_;
};

CowTalk::Ptr CowTalk::Create() {
  std::unique_ptr<Impl> impl =
    std::unique_ptr<Impl>(new Impl());
  std::unique_ptr<CowTalk> ptr =
    std::unique_ptr<CowTalk>(
        new CowTalk(impl));
  return std::move(ptr);
}

std::string CowTalk::talk() const {
  return impl->talk();
}

CowTalk::CowTalk(std::unique_ptr<Impl>& impl)
  : impl(std::move(impl)) {}

CowTalk::~CowTalk() {
  impl.reset();
}

}  // namespace cow_talk

struct CowTalkHandle {
  cow_talk::CowTalk::Ptr ptr;
};

CowTalkHandlePtr CowTalk_Create() {
  CowTalkHandlePtr handle = new CowTalkHandle();
  handle->ptr = cow_talk::CowTalk::Create();
  return handle;
}

char* CowTalk_Talk(CowTalkHandlePtr handle) {
  const std::string message = handle->ptr->talk();
  char* cstr = new char[message.length()+1];
  std::strcpy(cstr, message.c_str());
  return cstr;
}

void CowTalk_Destroy(void* p) {
  cow_talk::CowTalk* ptr =
    reinterpret_cast<cow_talk::CowTalk*>(p);
  delete ptr;
}
