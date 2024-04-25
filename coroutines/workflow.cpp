// https://en.cppreference.com/w/cpp/language/coroutines
// https://zhuanlan.zhihu.com/p/497224333

#include "common.hpp"
#include <thread>

namespace Coroutine {
struct task {
  struct promise_type {
    promise_type() { std::cout << "1.create promise object\n"; }
    task get_return_object() {
      std::cout << "2.create coroutine return object, and the coroutine is "
                   "created now\n";
      return {std::coroutine_handle<task::promise_type>::from_promise(*this)};
    }
    std::suspend_never initial_suspend() {
      std::cout << "3.do you want to suspend the current coroutine?\n";
      std::cout << "4.don't suspend because return std::suspend_never, so "
                   "continue to execute coroutine body\n";
      return {};
    }
    std::suspend_never final_suspend() noexcept {
      std::cout << "13.coroutine body finished, do you want to suspend the "
                   "current coroutine?\n";
      std::cout << "14.don't suspend because return std::suspend_never, and "
                   "the continue will be automatically destroyed, bye\n";
      return {};
    }
    void return_void() {
      std::cout
          << "12.coroutine don't return value, so return_void is called\n";
    }
    void unhandled_exception() {}
  };

  std::coroutine_handle<task::promise_type> handle_;
};

struct awaiter {
  bool await_ready() {
    std::cout << "6.do you want to suspend current coroutine?\n";
    std::cout << "7.yes, suspend because awaiter.await_ready() return false\n";
    return false;
  }
  void await_suspend(std::coroutine_handle<task::promise_type> handle) {
    std::cout << "8.execute awaiter.await_suspend()\n";
    std::thread([handle]() mutable { handle(); }).detach();
    std::cout << "9.a new thread launched, and will return back to caller\n";
  }
  void await_resume() {}
};

task test() {
  std::cout << "5.begin to execute coroutine body, the thread id="
            << std::this_thread::get_id() << "\n"; //#1
  co_await awaiter{};
  std::cout << "11.coroutine resumed, continue execute coroutine body now, "
               "the thread id="
            << std::this_thread::get_id() << "\n"; //#3
}
} // namespace Coroutine

int main() {
  Coroutine::test();
  std::cout << "10.come back to caller because of co_await awaiter\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));

  return 0;
}
