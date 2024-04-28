#pragma once

#include "common.hpp"
#undef SRCNAME
#define SRCNAME "cowaiter"

namespace CoroutineDef {

struct awaiter {
  bool await_ready() {
    print_line_func();
    return true;
  }
  void await_suspend(std::coroutine_handle<task::promise_type> handle) {
    print_line_func();
  }
  void await_resume() { print_line_func(); }
};

struct awaiter_async {
  awaiter_async() { print_line_func(); }
  ~awaiter_async() { print_line_func(); }
  bool await_ready() {
    print_line_func();
    return false;
  }
  bool await_suspend(std::coroutine_handle<task_async::promise_type> handle) {
    if (luckynum()) {
      print_line_func();
      return false;
    } else {
      print_line_func();
      luckynum_++;
      return true;
    }
  }
  void await_resume() { print_line_func(); }

  bool luckynum() { return luckynum_ == 3; }

  int luckynum_ = 0;
};

} // namespace CoroutineDef
