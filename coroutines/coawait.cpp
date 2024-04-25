#include "cotask.hpp"
#include "cowaiter.hpp"
#undef SRCNAME
#define SRCNAME "coawait"

namespace CoroutineRef {

CoroutineDef::task coawait() {
  print_line_func();
  co_await CoroutineDef::awaiter{};
}

} // namespace CoroutineRef

int main() {
  print_title();
  CoroutineRef::coawait();
  return 0;
}
