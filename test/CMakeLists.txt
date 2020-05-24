cmake_minimum_required (VERSION 3.6)
project (nodep2p_test)

set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-missing-braces -Wno-unused-function -std=c++14")

add_executable(nodep2p_test
        test.cpp)

target_link_libraries(nodep2p_test
        nodep2p
        boost_system
        boost_filesystem)
target_include_directories(nodep2p_test PRIVATE
        .
        ../src)
add_test(NAME nodep2p_unit_tests COMMAND nodep2p_test)