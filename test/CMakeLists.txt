cmake_minimum_required (VERSION 2.6)
project (nodep2p_test)

find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

include_directories (${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-missing-braces -Wno-unused-function -std=c++14")

add_executable(nodep2p_test
        test.cpp
        nodep2p/rsa_test.cpp)

target_link_libraries(
        nodep2p_test
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

target_link_libraries(nodep2p_test
nodep2p
${Boost_FILESYSTEM_LIBRARY}
${Boost_SYSTEM_LIBRARY}
${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
target_include_directories(nodep2p_test PRIVATE
        .
        ../src)
add_test(NAME nodep2p_unit_tests COMMAND nodep2p_test)