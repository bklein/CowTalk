#include <ruby.h>
#include <stdio.h>

#include "cowtalk.h"

static VALUE rb_CowTalk;

static VALUE ct_init(VALUE self) {
  return self;
}

static void ct_free(void *p) {
  CowTalk_Destroy(p);
}

static VALUE ct_talk(VALUE self) {
  struct CowTalkHandle* ptr;
  Data_Get_Struct(self, struct CowTalkHandle, ptr);
  const char* message = CowTalk_Talk(ptr);
  VALUE rb_str = rb_str_new2(message);
  return rb_str;
}

VALUE ct_new(VALUE class) {
  CowTalkHandlePtr ptr = CowTalk_Create();
  VALUE tdata = Data_Wrap_Struct(class, 0, ct_free, ptr);
  rb_obj_call_init(tdata, 0, NULL);
  return tdata;
}

void Init_CowTalk() {
  rb_CowTalk = rb_define_class("CowTalk", rb_cObject);
  rb_define_singleton_method(rb_CowTalk, "new", ct_new, 0);
  rb_define_method(rb_CowTalk, "initialize", ct_init, 0);
  rb_define_method(rb_CowTalk, "talk", ct_talk, 0);
}
