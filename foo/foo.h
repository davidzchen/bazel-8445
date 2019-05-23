#ifndef FOO_FOO_H_
#define FOO_FOO_H_

#include <string>

#include "absl/strings/string_view.h"

namespace foo {

class Foo {
 public:
  Foo();
  ~Foo();

  static std::string TakeString(absl::string_view str);
};

}  // namespace foo

#endif  // FOO_FOO_H_
