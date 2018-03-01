find_path(SPDLOG_INCLUDE_DIR spdlog/spdlog.h HINT ${EXTERNAL_ROOT}/include)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(spdlog DEFAULT_MSG SPDLOG_INCLUDE_DIR)
