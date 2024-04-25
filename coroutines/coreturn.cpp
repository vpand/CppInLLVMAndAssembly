#include "cotask.hpp"
#undef SRCNAME
#define SRCNAME "coreturn"

namespace CoroutineRef {

CoroutineDef::task coreturn() {
  print_line_func();
  co_return;
}

} // namespace CoroutineRef

int main() {
  print_title();
  CoroutineRef::coreturn();
  return 0;
}
