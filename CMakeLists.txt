cmake_minimum_required(VERSION 3.1.0)

project (node-p2p)
include(FetchContent)

 add_executable(node-p2p node-p2p.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/build/default)


target_include_directories(node-p2p
        PRIVATE
        src)
 target_link_libraries(
    ${PROJECT_NAME}
     )