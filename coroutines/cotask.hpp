#pragma once

#include "common.hpp"
#undef SRCNAME
#define SRCNAME "cotask"

namespace CoroutineDef {

struct task {
  struct promise_type {
    promise_type() { print_line_func(); }

    ~promise_type() { print_line_func(); }

    task get_return_object() {
      print_line_func();
      return {std::coroutine_handle<task::promise_type>::from_promise(*this)};
    }

    std::suspend_never initial_suspend() {
      print_line_func();
      return {};
    }

    std::suspend_never final_suspend() noexcept {
      print_line_func();
      return {};
    }

    void return_void() { print_line_func(); }

    void unhandled_exception() { print_line_func(); }
  };

  std::coroutine_handle<task::promise_type> handle_;
};

} // namespace CoroutineDef
