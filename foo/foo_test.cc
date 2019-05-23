#include "foo/foo.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace foo {
namespace {

TEST(FooTest, BaseCase) {
  Foo foo;
  EXPECT_THAT(Foo::TakeString("bar"), ::testing::Eq("bar"));
}

}
}  // namespace foo
