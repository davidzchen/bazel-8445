package(default_visibility = ["//foo:__subpackages__"])

cc_library(
    name = "foo",
    srcs = ["foo.cc"],
    hdrs = ["foo.h"],
    deps = [
        "@com_google_absl//absl/strings",
    ],
)

cc_test(
    name = "foo_test",
    srcs = ["foo_test.cc"],
    #linkstatic = 1,
    deps = [
        ":foo",
        "@com_google_googletest//:gtest_main",
    ],
)
