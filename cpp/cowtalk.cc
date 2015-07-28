#include <sstream>

#include "cowtalk.hpp"
#include "cowtalk.h"

namespace cow_talk {

class CowTalk::Impl {
 public:
  Impl(const std::string& message)
    : message_(message),
      touched_cache_(),
      times_touched_(0) {}

  const std::string& Talk() const { return message_; }
  int TimesTouched() const { return times_touched_; }

  const std::string& Touch() {
    ++times_touched_;
    std::stringstream ss;
    ss << "Ew, I've been touched " << times_touched_ << " times.";
    touched_cache_ = ss.str();
    return touched_cache_;
  }

  ~Impl() {}

 private:
  const std::string message_;
  std::string touched_cache_;
  int times_touched_;
};

CowTalk::Ptr CowTalk::Create(const std::string& message) {
  std::unique_ptr<Impl> impl =
    std::unique_ptr<Impl>(new Impl(message));
  std::unique_ptr<CowTalk> ptr =
    std::unique_ptr<CowTalk>(
        new CowTalk(impl));
  return std::move(ptr);
}

const std::string& CowTalk::Talk() const {
  return impl->Talk();
}

const std::string& CowTalk::Touch() {
  return impl->Touch();
}

int CowTalk::TimesTouched() const {
  return impl->TimesTouched();
}

CowTalk::CowTalk(std::unique_ptr<Impl>& impl)
  : impl(std::move(impl)) {}

CowTalk::~CowTalk() {
  impl.reset();
}

}  // namespace cow_talk

// C API:

struct CowTalkHandle {
  cow_talk::CowTalk::Ptr ptr;
};

CowTalkHandle* CowTalk_Create(const char* message) {
  CowTalkHandle* handle = new CowTalkHandle();
  if (!message) {
    handle->ptr = cow_talk::CowTalk::Create();
  } else {
    const std::string str_message(message);
    handle->ptr = cow_talk::CowTalk::Create(str_message);
  }
  return handle;
}

const char* CowTalk_Talk(const CowTalkHandle* const handle) {
  return handle->ptr->Talk().c_str();
}

const char* CowTalk_Touch(CowTalkHandle* handle) {
  return handle->ptr->Touch().c_str();
}

int CowTalk_TimesTouched(const CowTalkHandle* const handle) {
  return handle->ptr->TimesTouched();
}

void CowTalk_Destroy(void* p) {
  cow_talk::CowTalk* ptr =
    reinterpret_cast<cow_talk::CowTalk*>(p);
  delete ptr;
}
