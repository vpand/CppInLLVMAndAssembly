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

    std::suspend_never yield_value(const char *value) {
      print_line_func();
      value_ = value;
      return {};
    }

    const char *value_;
  };

  const char *value() { return handle_.promise().value_; }

  std::coroutine_handle<task::promise_type> handle_;
};

struct task_async {
  ~task_async() {
    print_line_func();
    handle_.destroy();
  }

  struct promise_type {
    promise_type() { print_line_func(); }

    ~promise_type() { print_line_func(); }

    task_async get_return_object() {
      print_line_func();
      return {
          std::coroutine_handle<task_async::promise_type>::from_promise(*this)};
    }

    std::suspend_always initial_suspend() {
      print_line_func();
      return {};
    }

    std::suspend_always final_suspend() noexcept {
      print_line_func();
      return {};
    }

    void return_void() { print_line_func(); }

    void unhandled_exception() { print_line_func(); }
  };

  std::coroutine_handle<task_async::promise_type> handle_;
};

struct task_yield_async {
  ~task_yield_async() {
    print_line_func();
    handle_.destroy();
  }

  struct promise_type;
  struct awaiter_async {
    awaiter_async() { print_line_func(); }
    ~awaiter_async() { print_line_func(); }
    bool await_ready() {
      print_line_func();
      return false;
    }
    bool await_suspend(
        std::coroutine_handle<task_yield_async::promise_type> handle) {
      if (handle.promise().done()) {
        print_line_func();
        return false;
      } else {
        print_line_func();
        return true;
      }
    }
    void await_resume() { print_line_func(); }
  };

  struct promise_type {
    promise_type() { print_line_func(); }

    ~promise_type() { print_line_func(); }

    task_yield_async get_return_object() {
      print_line_func();
      return {
          std::coroutine_handle<task_yield_async::promise_type>::from_promise(
              *this)};
    }

    std::suspend_always initial_suspend() {
      print_line_func();
      return {};
    }

    std::suspend_always final_suspend() noexcept {
      print_line_func();
      return {};
    }

    void return_void() { print_line_func(); }

    void unhandled_exception() { print_line_func(); }

    task_yield_async::awaiter_async yield_value(char value) {
      print_line_func();
      if (cur_ + 1 == maxchs_) {
        // force being done
        value = '.';
      }
      chs_[cur_++] = value;
      return {};
    }

    bool done() { return cur_ && chs_[cur_ - 1] == '.'; }

    static const int maxchs_ = 128;
    char chs_[maxchs_];
    int cur_ = 0;
  };

  const char *value() { return handle_.promise().chs_; }

  std::coroutine_handle<task_yield_async::promise_type> handle_;
};

} // namespace CoroutineDef
