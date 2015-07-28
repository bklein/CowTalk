#include <stdio.h>
#include "cowtalk.h"

int main(int argc, char** argv) {

  /*
   * C++:
   *
   * cow_talk::CowTalk::Ptr cow_talk =
   *  cow_talk::CowTalk::Create();
   *
   *  std::out << "cow said: " << cow_talk->Talk() << std::endl;
   *
   */

  CowTalkHandle* cow_talk = CowTalk_Create(NULL);
  const char* talk = CowTalk_Talk(cow_talk);
  printf("cow said: %s\n", talk);
  CowTalk_Destroy(cow_talk);

  return 0;
}
