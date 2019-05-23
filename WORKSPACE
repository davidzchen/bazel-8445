workspace(name = "com_google_bazel_507")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_google_absl",
    urls = ["https://github.com/abseil/abseil-cpp/archive/master.zip"],
    strip_prefix = "abseil-cpp-master",
)

# Workspace rules needed by `@com_google_absl`.
http_archive(
     name = "com_google_googletest",
     urls = ["https://github.com/google/googletest/archive/master.zip"],
     strip_prefix = "googletest-master",
)

http_archive(
    name = "com_googlesource_code_cctz",
    urls = ["https://github.com/google/cctz/archive/master.zip"],
    strip_prefix = "cctz-master",
)

http_archive(
    name = "com_googlesource_code_re2",
    urls = ["https://github.com/google/re2/archive/master.zip"],
    strip_prefix = "re2-master",
)
