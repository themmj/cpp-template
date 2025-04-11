include(FetchContent)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.x
  GIT_SHALLOW    1 # avoid cloning unneeded branches
)

FetchContent_MakeAvailable(spdlog)
