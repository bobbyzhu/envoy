package(default_visibility = ["//visibility:public"])

load("//bazel:envoy_build_system.bzl", "envoy_cc_binary", "envoy_cc_test_library")

envoy_cc_binary(
    name = "router_check_tool",
    testonly = 1,
    deps = [":router_check_main_lib"],
)

envoy_cc_test_library(
    name = "router_check_main_lib",
    srcs = [
        "router.cc",
        "router.h",
        "router_check.cc",
    ],
    deps = [
        "//source/common/http:header_map_lib",
        "//source/common/http:headers_lib",
        "//source/common/json:json_loader_lib",
        "//source/common/router:config_lib",
        "//test/mocks/runtime:runtime_mocks",
        "//test/mocks/upstream:upstream_mocks",
        "//test/test_common:printers_lib",
        "//test/test_common:utility_lib",
        "//test/tools/router_check/json:tool_config_schemas_lib",
    ],
)
