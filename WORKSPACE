workspace(name = "com_google_bazel_507")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_google_absl",
    urls = ["https://github.com/abseil/abseil-cpp/archive/master.zip"],
    strip_prefix = "abseil-cpp-master",
)

# Needed by proto_library rules and cc_proto_library support. These rules are
# duplicated because there is no way to alias http_archive rules currently.
http_archive(
    name = "com_google_protobuf",
    urls = [
        "https://github.com/protocolbuffers/protobuf/archive/v3.8.0-rc1.zip"
    ],
    sha256 = "93a0153b179ef0ceddc1ecb1bd902feae6c89fc31c218cd25c976658103c70b1",
    strip_prefix = "protobuf-3.8.0-rc1",
)

http_archive(
    name = "com_google_protobuf_cc",
    urls = [
        "https://github.com/protocolbuffers/protobuf/archive/v3.8.0-rc1.zip"
    ],
    sha256 = "93a0153b179ef0ceddc1ecb1bd902feae6c89fc31c218cd25c976658103c70b1",
    strip_prefix = "protobuf-3.8.0-rc1",
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

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

# Workspace rules needed by `@com_google_protobuf`.

http_archive(
    name = "bazel_skylib",
    sha256 = "bbccf674aa441c266df9894182d80de104cabd19be98be002f6d478aaa31574d",
    strip_prefix = "bazel-skylib-2169ae1c374aab4a09aa90e65efe1a3aad4e279b",
    urls = ["https://github.com/bazelbuild/bazel-skylib/archive/2169ae1c374aab4a09aa90e65efe1a3aad4e279b.tar.gz"],
)
