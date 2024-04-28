#include "cotask.hpp"
#undef SRCNAME
#define SRCNAME "coyield"

namespace CoroutineRef {

CoroutineDef::task_yield_async coyield_async() {
  print_line_func();
  co_yield 'O';
  print_line_func();
  co_yield 'K';
  print_line_func();
  co_yield '.';
  print_line_func();
}

} // namespace CoroutineRef

int main() {
  print_title();
  auto task = CoroutineRef::coyield_async();
  while (!task.handle_.done()) {
    print_line_func();
    task.handle_.resume();
  }
  puts(task.value());
  return 0;
}
