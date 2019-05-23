# bazelbuild/bazel#8445 Reproduction case

## To reproduce

```sh
$ git clone https://github.com/davidzchen/bazel-8445
$ cd bazel-8445
$ bazel test //foo:foo_test --test_output=errors
```

## Expected failures

```
$ bazel test //foo:foo_test --test_output=errors
DEBUG: Rule 'com_google_absl' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = "5d9fbe5a4239e9e76324bee6d70b63af1be0066c8d10ae11366e25f594495fff"
DEBUG: Call stack for the definition of repository 'com_google_absl' which is a http_archive (rule definition at /private/var/tmp/_bazel_dzc/df81d8fb4cd81e4ef0a6151c52c3a958/external/bazel_tools/tools/build_defs/repo/http.bzl:237:16):
 - /Volumes/oasis/Projects/experimental/bazel-8445/WORKSPACE:5:1
DEBUG: Rule 'com_google_googletest' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = "b1c3ddb37427f9afcc8c91aee7b21826bf0cda54dc17d64c001a67ad2cf97250"
DEBUG: Call stack for the definition of repository 'com_google_googletest' which is a http_archive (rule definition at /private/var/tmp/_bazel_dzc/df81d8fb4cd81e4ef0a6151c52c3a958/external/bazel_tools/tools/build_defs/repo/http.bzl:237:16):
 - /Volumes/oasis/Projects/experimental/bazel-8445/WORKSPACE:12:1
INFO: Analyzed target //foo:foo_test (1 packages loaded, 5 targets configured).
INFO: Found 1 test target...
FAIL: //foo:foo_test (see /private/var/tmp/_bazel_dzc/df81d8fb4cd81e4ef0a6151c52c3a958/execroot/com_google_bazel_507/bazel-out/darwin-fastbuild/testlogs/foo/foo_test/test.log)
INFO: From Testing //foo:foo_test:
==================== Test output for //foo:foo_test:
Running main() from gmock_main.cc
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from FooTest
[ RUN      ] FooTest.BaseCase
dyld: lazy symbol binding failed: Symbol not found: __ZN3foo3FooC1Ev
  Referenced from: /private/var/tmp/_bazel_dzc/df81d8fb4cd81e4ef0a6151c52c3a958/sandbox/darwin-sandbox/66/execroot/com_google_bazel_507/bazel-out/darwin-fastbuild/bin/foo/foo_test.runfiles/com_google_bazel_507/foo/foo_test
  Expected in: flat namespace

dyld: Symbol not found: __ZN3foo3FooC1Ev
  Referenced from: /private/var/tmp/_bazel_dzc/df81d8fb4cd81e4ef0a6151c52c3a958/sandbox/darwin-sandbox/66/execroot/com_google_bazel_507/bazel-out/darwin-fastbuild/bin/foo/foo_test.runfiles/com_google_bazel_507/foo/foo_test
  Expected in: flat namespace

external/bazel_tools/tools/test/test-setup.sh: line 310: 63517 Abort trap: 6           "${TEST_PATH}" "$@" 2>&1
================================================================================
Target //foo:foo_test up-to-date:
  bazel-bin/foo/foo_test
INFO: Elapsed time: 0.803s, Critical Path: 0.62s
INFO: 13 processes: 13 darwin-sandbox.
INFO: Build completed, 1 test FAILED, 25 total actions
//foo:foo_test                                                           FAILED in 0.1s
  /private/var/tmp/_bazel_dzc/df81d8fb4cd81e4ef0a6151c52c3a958/execroot/com_google_bazel_507/bazel-out/darwin-fastbuild/testlogs/foo/foo_test/test.log

INFO: Build completed, 1 test FAILED, 25 total actions
```

Setting `linkstatic = 1` on `//foo:foo_test` results in the following linker
error instead:

```
$ bazel test //foo:foo_test --test_output=errors                                                                                                                                                                                                                                                                                                                                                                                                                                                                           experimental/bazel-8445
DEBUG: Rule 'com_google_googletest' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = "b1c3ddb37427f9afcc8c91aee7b21826bf0cda54dc17d64c001a67ad2cf97250"
DEBUG: Call stack for the definition of repository 'com_google_googletest' which is a http_archive (rule definition at /private/var/tmp/_bazel_dzc/df81d8fb4cd81e4ef0a6151c52c3a958/external/bazel_tools/tools/build_defs/repo/http.bzl:237:16):
 - /Volumes/oasis/Projects/experimental/bazel-8445/WORKSPACE:12:1
DEBUG: Rule 'com_google_absl' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = "5d9fbe5a4239e9e76324bee6d70b63af1be0066c8d10ae11366e25f594495fff"
DEBUG: Call stack for the definition of repository 'com_google_absl' which is a http_archive (rule definition at /private/var/tmp/_bazel_dzc/df81d8fb4cd81e4ef0a6151c52c3a958/external/bazel_tools/tools/build_defs/repo/http.bzl:237:16):
 - /Volumes/oasis/Projects/experimental/bazel-8445/WORKSPACE:5:1
INFO: Analyzed target //foo:foo_test (0 packages loaded, 0 targets configured).
INFO: Found 1 test target...
ERROR: /Volumes/oasis/Projects/experimental/bazel-8445/foo/BUILD:12:1: Linking of rule '//foo:foo_test' failed (Exit 1) cc_wrapper.sh failed: error executing command external/local_config_cc/cc_wrapper.sh -lc++ -fobjc-link-runtime -Wl,-S -o bazel-out/darwin-fastbuild/bin/foo/foo_test bazel-out/darwin-fastbuild/bin/foo/_objs/foo_test/foo_test.o ... (remaining 15 argument(s) skipped)

Use --sandbox_debug to see verbose messages from the sandbox
Undefined symbols for architecture x86_64:
  "foo::Foo::TakeString(absl::string_view)", referenced from:
      foo::(anonymous namespace)::FooTest_BaseCase_Test::TestBody() in foo_test.o
  "foo::Foo::Foo()", referenced from:
      foo::(anonymous namespace)::FooTest_BaseCase_Test::TestBody() in foo_test.o
  "foo::Foo::~Foo()", referenced from:
      foo::(anonymous namespace)::FooTest_BaseCase_Test::TestBody() in foo_test.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
Target //foo:foo_test failed to build
Use --verbose_failures to see the command lines of failed build steps.
INFO: Elapsed time: 0.259s, Critical Path: 0.10s
INFO: 0 processes.
FAILED: Build did NOT complete successfully

FAILED: Build did NOT complete successfully
```
