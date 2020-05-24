cmake_minimum_required(VERSION 3.1.0)

project (nodep2p)
include(FetchContent)
FetchContent_Declare(spotify-json
GIT_REPOSITORY https://github.com/spotify/spotify-json
GIT_TAG v1.0.1)

FetchContent_GetProperties(spotify-json)
if(NOT spotify-json_POPULATED)
  FetchContent_Populate(spotify-json)
  add_subdirectory(${spotify-json_SOURCE_DIR} ${spotify-json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


enable_testing()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/build/default)
set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-unused-variable -Wno-sign-compare -Wno-missing-braces -Wno-unused-function -std=c++14")

add_executable(nodep2p src/main.cpp)

target_include_directories(nodep2p
        PRIVATE
        src)

 target_link_libraries(
    ${PROJECT_NAME}
    spotify-json
)

