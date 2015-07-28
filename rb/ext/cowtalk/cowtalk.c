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

static VALUE ct_touch(VALUE self) {
  struct CowTalkHandle* ptr;
  Data_Get_Struct(self, struct CowTalkHandle, ptr);
  const char* touch = CowTalk_Touch(ptr);
  VALUE rb_touch = rb_str_new2(touch);
  return rb_touch;
}

static VALUE ct_times_touched(VALUE self) {
  struct CowTalkHandle* ptr;
  Data_Get_Struct(self, struct CowTalkHandle, ptr);
  const int times_touched = CowTalk_TimesTouched(ptr);
  VALUE rb_times_touched = INT2NUM(times_touched);
  return rb_times_touched;
}

VALUE ct_new(VALUE class) {
  CowTalkHandle* ptr = CowTalk_Create();
  VALUE tdata = Data_Wrap_Struct(class, 0, ct_free, ptr);
  rb_obj_call_init(tdata, 0, NULL);
  return tdata;
}

void Init_CowTalk() {
  rb_CowTalk = rb_define_class("CowTalk", rb_cObject);
  rb_define_singleton_method(rb_CowTalk, "new", ct_new, 0);
  rb_define_method(rb_CowTalk, "initialize", ct_init, 0);
  rb_define_method(rb_CowTalk, "talk", ct_talk, 0);
  rb_define_method(rb_CowTalk, "touch", ct_touch, 0);
  rb_define_method(rb_CowTalk, "times_touched", ct_times_touched, 0);
}
