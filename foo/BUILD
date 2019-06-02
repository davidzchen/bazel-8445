package(default_visibility = ["//foo:__subpackages__"])

proto_library(
    name = "foo_proto",
    srcs = ["foo.proto"],
)

cc_proto_library(
    name = "foo_cc_proto",
    deps = [":foo_proto"],
)

cc_library(
    name = "foo",
    srcs = ["foo.cc"],
    hdrs = ["foo.h"],
    deps = [
        ":foo_cc_proto",
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
