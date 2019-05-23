#include "foo/foo.h"

namespace foo {

std::string TakeString(absl::string_view str) {
  return std::string(str);
}

}  // namespace foo
