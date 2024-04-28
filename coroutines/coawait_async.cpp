#include "cotask.hpp"
#include "cowaiter.hpp"
#undef SRCNAME
#define SRCNAME "coawait"

namespace CoroutineRef {

CoroutineDef::task_async coawait_async() {
  print_line_func();
  CoroutineDef::awaiter_async aa{};
  while (!aa.luckynum()) {
    print_line_func();
    co_await aa;
  }
  print_line_func();
}

} // namespace CoroutineRef

int main() {
  print_title();
  auto task = CoroutineRef::coawait_async();
  while (!task.handle_.done()) {
    print_line_func();
    task.handle_.resume();
  }
  print_line_func();
  return 0;
}
