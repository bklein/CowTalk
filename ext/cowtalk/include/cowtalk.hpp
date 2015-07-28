#ifndef COWTALK_HPP_
#define COWTALK_HPP_
#include <memory>
#include <string>

namespace cow_talk {

class CowTalk {
 public:
  typedef std::unique_ptr<CowTalk> Ptr;
  static Ptr Create(const std::string& message = "I'm a cow, moo");
  const std::string& Talk() const;
  const std::string& Touch();
  int TimesTouched() const;
  ~CowTalk();
 private:
  class Impl;
  std::unique_ptr<Impl> impl;
  CowTalk(std::unique_ptr<Impl>& impl);
};

}  // namespace cow_talk

#endif  // COWTALK_HPP_
