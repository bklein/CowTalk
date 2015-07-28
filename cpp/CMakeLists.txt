cmake_minimum_required(VERSION 2.8)

project(CowTalk C CXX)

add_library(CowTalk STATIC
  cowtalk.cc)

add_executable(cow_talk
  cowtalkapp.c)
target_link_libraries(cow_talk
  CowTalk)

install(TARGETS CowTalk
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
install(FILES cowtalk.h DESTINATION include)
