#include "foo/foo.h"

namespace foo {

Foo::Foo(const FooMessage& proto)
    : proto_(proto) {}

Foo Foo::FromProto(const FooMessage& proto) {
  // DUMMY: Do some validation.
  return Foo(proto);
}

absl::string_view Foo::name() const {
  return proto_.name();
}

}  // namespace foo
