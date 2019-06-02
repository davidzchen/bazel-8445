#ifndef FOO_FOO_H_
#define FOO_FOO_H_

#include <string>

#include "foo/foo.pb.h"
#include "absl/strings/string_view.h"

namespace foo {

class Foo {
 public:
  static Foo FromProto(const FooMessage& proto);
  ~Foo();

  absl::string_view name() const;

 private:
  Foo(const FooMessage& proto);
  FooMessage proto_;
};

}  // namespace foo

#endif  // FOO_FOO_H_
