cmake_minimum_required(VERSION 3.1.0)
enable_testing()
set(PROJECT_NAME_STR nodep2p)
project(${PROJECT_NAME_STR})
include(FetchContent)
FetchContent_Declare(spotify-json
GIT_REPOSITORY https://github.com/spotify/spotify-json
GIT_TAG v1.0.1)

find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)
if (APPLE)
    # This is a bug in CMake that causes it to prefer the system version over
    # the one in the specified ROOT folder.
    set(OPENSSL_ROOT_DIR ${OPENSSL_ROOT_DIR} /usr/local/Cellar/openssl@1.1/1.1.1g/)
    set(OPENSSL_CRYPTO_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libcrypto.dylib CACHE FILEPATH "" FORCE)
    set(OPENSSL_SSL_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libssl.dylib CACHE FILEPATH "" FORCE)
endif()
find_package(OpenSSL REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

FetchContent_GetProperties(spotify-json)
if(NOT spotify-json_POPULATED)
  FetchContent_Populate(spotify-json)
  add_subdirectory(${spotify-json_SOURCE_DIR} ${spotify-json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


enable_testing()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/build/default)
set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-unused-variable -Wno-sign-compare -Wno-missing-braces -Wno-unused-function -std=c++14")




        
add_library(nodep2p
        src/nodep2p/crypto/crypto_exception.h
        src/nodep2p/crypto/pki.h
        src/nodep2p/cryptokey/cryptokeypair.h
        src/nodep2p/cryptokey/public_key.h
        src/nodep2p/crypto/base64.h
        src/nodep2p/crypto/rsa.h
        src/nodep2p/crypto/rsa.cpp
        src/nodep2p/crypto/base64.cpp
        )

target_include_directories(nodep2p
        PUBLIC
        src)
        

add_subdirectory(test)


 target_link_libraries(
    nodep2p
    spotify-json
    OpenSSL::SSL
    OpenSSL::Crypto
)

