#include "foo/foo.h"

#include "foo/foo.pb.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace foo {
namespace {

TEST(FooTest, BaseCase) {
  FooMessage msg;
  msg.set_name("foo");
  EXPECT_THAT(Foo::FromProto(msg).name(), ::testing::Eq("foo"));
}

}
}  // namespace foo
