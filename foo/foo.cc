#include "foo/foo.h"

namespace foo {

std::string Foo::TakeString(absl::string_view str) {
  return std::string(str);
}

}  // namespace foo
