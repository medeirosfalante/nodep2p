cmake_minimum_required(VERSION 3.1.0)

project (node-p2p)
include(FetchContent)

 add_executable(node-p2p node-p2p.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/build/default)


 FetchContent_Declare(spotify-json
  GIT_REPOSITORY https://github.com/spotify/spotify-json
  GIT_TAG v1.0.1)

FetchContent_GetProperties(spotify-json)
if(NOT spotify-json_POPULATED)
  FetchContent_Populate(spotify-json)
  add_subdirectory(${spotify-json_SOURCE_DIR} ${spotify-json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


target_include_directories(node-p2p
        PRIVATE
        src)
 target_link_libraries(
    ${PROJECT_NAME}
    spotify-json
     )