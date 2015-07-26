#include <stdio.h>
#include "cowtalk.h"

int main(int argc, char** argv) {
  CowTalkHandlePtr cow_talk = CowTalk_Create();
  char* talk = CowTalk_Talk(cow_talk);
  printf("cow said: %s\n", talk);

  return 0;
}
