#include "cotask.hpp"
#undef SRCNAME
#define SRCNAME "coyield"

namespace CoroutineRef {

CoroutineDef::task coyield() {
  print_line_func();
  co_yield "Hello, world.";
}

} // namespace CoroutineRef

int main() {
  print_title();
  puts(CoroutineRef::coyield().value());
  return 0;
}
