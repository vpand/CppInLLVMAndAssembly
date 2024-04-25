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

} // namespace CoroutineDef
